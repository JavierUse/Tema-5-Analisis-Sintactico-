import re
import difflib

# Palabras clave y símbolos válidos en UnegScript
PALABRAS_CLAVE = ["if", "else", "print", "prnt"] # Incluimos variantes para detectar errores comunes
TOKENS_VALIDOS = {
    "if": "TK_IF",
    "else": "TK_ELSE",
    "print": "TK_PRINT",
    "prnt": "TK_PRINT", # Será marcado para corrección
    "pront": "TK_PRINT" # Variante mal escrita común
}

class LexerHibrido:
    def __init__(self, codigo_fuente):
        self.codigo_fuente = codigo_fuente
        self.tokens_corregidos = []
        self.sugerencias_ia = []

    def calcular_similitud(self, s1, s2):
        # Fórmula de ratio basada en Levenshtein / SequenceMatcher descrita en el documento
        return difflib.SequenceMatcher(None, s1, s2).ratio()

    def consultar_ia_fallback(self, lexeme):
        # Simulación de la consulta al LLM cuando la confianza es < 0.8
        # En un entorno real, aquí harías una petición HTTP a la API de OpenAI/Gemini
        if lexeme in ("pront", "prnt"):
            return "print"
        return lexeme

    def tokenizar(self):
        # Expresión regular para separar palabras, operadores, símbolos y cadenas
        patron = r'(==|!=|>=|<=|[a-zA-Z_]\w*|\d+|["\'].*?["\']|[^\s])'
        elementos = re.findall(patron, self.codigo_fuente)

        for lexema in elementos:
            # Ignorar espacios o símbolos sueltos extraños si es necesario
            if lexema.strip() == "":
                continue
            # Ignorar delimitador '$' usado erróneamente en el código de ejemplo
            if lexema == '$':
                # registrar sugerencia mínima para trazabilidad
                if hasattr(self.sugerencias_ia, 'append'):
                    self.sugerencias_ia.append(f"Sugerencia (ignorar delimitador): '{lexema}' removed")
                continue

            # Verificar si es palabra clave o identificador
            if lexema in TOKENS_VALIDOS or re.match(r'^[a-zA-Z_]\w*$', lexema):
                if lexema in TOKENS_VALIDOS:
                    token_tipo = TOKENS_VALIDOS[lexema]
                    token_valor = lexema
                    
                    # Normalizar variantes erróneas de 'print'
                    if lexema in ("pront", "prnt"):
                        sugerencia = self.consultar_ia_fallback(lexema)
                        if hasattr(self.sugerencias_ia, 'sugerencia'):
                            self.sugerencias_ia.sugerencia(f"Sugerencia: '{lexema}' → '{sugerencia}'")
                        else:
                            self.sugerencias_ia.append(f"Sugerencia: '{lexema}' → '{sugerencia}'")
                        token_valor = sugerencia
                        token_tipo = "TK_PRINT"
                else:
                    token_tipo = "TK_ID"
                    token_valor = lexema
                
                self.tokens_corregidos.append((token_tipo, token_valor))
            
            elif re.match(r'^\d+$', lexema):
                self.tokens_corregidos.append(("TK_INT", lexema))
            
            elif lexema in ['=', '>', '<', '+', '-', '*', '/']:
                self.tokens_corregidos.append(("TK_OPERADOR", lexema))
            
            elif lexema in [';', '(', ')', '{', '}', '~']:
                # El símbolo '~' es común como separador erróneo en el ejemplo del profesor
                self.tokens_corregidos.append(("TK_SIMBOLO", lexema))
            
            elif lexema.startswith('"') and lexema.endswith('"'):
                self.tokens_corregidos.append(("TK_STRING", lexema))
            
            else:
                # Comprobación de similitud si hay un token desconocido o ambiguo
                mejor_match = None
                max_ratio = 0.0
                for candidato in TOKENS_VALIDOS.keys():
                    ratio = self.calcular_similitud(lexema, candidato)
                    if ratio > max_ratio:
                        max_ratio = ratio
                        mejor_match = candidato
                
                # Si el umbral es menor a 0.8, se activa el fallback a IA
                if max_ratio < 0.8:
                    sugerido = self.consultar_ia_fallback(lexema)
                    self.sugerencias_ia.append(f"Sugerencia (IA Fallback < 0.8): '{lexema}' → '{sugerido}'")
                    self.tokens_corregidos.append(("TK_CORREGIDO_IA", sugerido))
                else:
                    self.tokens_corregidos.append(("TK_DESCONOCIDO", lexema))

        return self.tokens_corregidos, self.sugerencias_ia

# Clase auxiliar para manejar la lista de sugerencias con método personalizado
class ListaSugerencias(list):
    def sugerencia(self, texto):
        self.append(texto)