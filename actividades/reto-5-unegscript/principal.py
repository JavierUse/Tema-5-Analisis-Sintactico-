from analizador_lexico import LexerHibrido, ListaSugerencias
from analizador_sintactico import ParserRecursivo

def ejecutar_asistente():
    # Código de ejemplo provisto en la actividad con errores deliberados[cite: 1]
    codigo_prueba = 'pront $x=5$; if $x>3~prnt(x)$ else prnt("no")'
    
    print("=" * 60)
    print("EJECUCIÓN DEL ASISTENTE HÍBRIDO (UNEGSCRIPT)")
    print("=" * 60)
    print(f"Código fuente de entrada: {codigo_prueba}\n")

    # 1. Fase del Lexer Híbrido
    lexer = LexerHibrido(codigo_prueba)
    # Inicializar la lista de sugerencias con la clase auxiliar definida en el lexer
    lexer.sugerencias_ia = ListaSugerencias()
    tokens, sugerencias_lexer = lexer.tokenizar()

    print("--- 1. TOKENS CORREGIDOS ---")
    for t in tokens:
        print(t)
    print()

    # 2. Fase del Parser con Lookahead e IA
    parser = ParserRecursivo(tokens)
    ast_nodos, sugerencias_parser = parser.analizar()

    print("--- 2. ÁRBOL DE SINTAXIS ABSTRACTA (AST) ---")
    for nodo in ast_nodos:
        print(nodo)
    print()

    print("--- 3. SUGERENCIAS DE LA IA ---")
    # 1) Combinar sugerencias del lexer y del parser
    todas_sugerencias = list(sugerencias_lexer) + list(sugerencias_parser)
    # 2) Desduplicar usando set y 3) ordenar alfabéticamente
    sugerencias_unicas = sorted(set(todas_sugerencias))

    if sugerencias_unicas:
        for sug in sugerencias_unicas:
            # Imprimir en el formato solicitado: - [Sugerencia]
            print(f"- [{sug}]")
    else:
        print("No se requirieron sugerencias adicionales.")
    print("=" * 60)

if __name__ == "__main__":
    ejecutar_asistente()