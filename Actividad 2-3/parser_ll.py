
"""
PARSER LL(1) - RECURSIVO DESCENDENTE
Lenguaje: Calculadora de Expresiones Aritmeticas
Autor: Generado para UNEG - Lenguaje y Compiladores 2026-I

Gramatica LL(1) (sin recursion izquierda, factorizada):
E  -> T E1
E1 -> + T E1 | - T E1 | epsilon
T  -> F T1
T1 -> * F T1 | / F T1 | epsilon
F  -> ( E ) | NUM
NUM -> [0-9]+
"""

class Token:
    def __init__(self, tipo, valor, linea=1, columna=1):
        self.tipo = tipo
        self.valor = valor
        self.linea = linea
        self.columna = columna

    def __repr__(self):
        return f"Token({self.tipo}, '{self.valor}')"

class LexerLL:
    """Lexer simple basado en AFD para la calculadora"""

    def __init__(self, texto):
        self.texto = texto
        self.pos = 0
        self.linea = 1
        self.columna = 1
        self.tokens = []

    def error(self, msg):
        raise SyntaxError(f"Error lexico en linea {self.linea}, columna {self.columna}: {msg}")

    def avanzar(self):
        if self.pos < len(self.texto) and self.texto[self.pos] == '\n':
            self.linea += 1
            self.columna = 1
        else:
            self.columna += 1
        self.pos += 1

    def peek(self):
        if self.pos >= len(self.texto):
            return None
        return self.texto[self.pos]

    def tokenizar(self):
        while self.pos < len(self.texto):
            char = self.peek()

            # Ignorar espacios en blanco
            if char in ' \t\n\r':
                self.avanzar()
                continue

            # Numeros
            if char.isdigit():
                inicio = self.pos
                linea_inicio = self.linea
                col_inicio = self.columna
                while self.peek() is not None and self.peek().isdigit():
                    self.avanzar()
                valor = self.texto[inicio:self.pos]
                self.tokens.append(Token('NUM', int(valor), linea_inicio, col_inicio))
                continue

            # Operadores y parentesis (un solo caracter)
            if char in '+-*/()':
                if char == '+':
                    self.tokens.append(Token('PLUS', '+', self.linea, self.columna))
                elif char == '-':
                    self.tokens.append(Token('MINUS', '-', self.linea, self.columna))
                elif char == '*':
                    self.tokens.append(Token('MULT', '*', self.linea, self.columna))
                elif char == '/':
                    self.tokens.append(Token('DIV', '/', self.linea, self.columna))
                elif char == '(':
                    self.tokens.append(Token('LPAREN', '(', self.linea, self.columna))
                elif char == ')':
                    self.tokens.append(Token('RPAREN', ')', self.linea, self.columna))
                self.avanzar()
                continue

            self.error(f"Caracter inesperado: '{char}'")

        self.tokens.append(Token('EOF', 'EOF', self.linea, self.columna))
        return self.tokens


class NodoAST:
    """Nodo base para el Arbol de Sintaxis Abstracta"""
    def __init__(self, tipo, valor=None, hijos=None):
        self.tipo = tipo
        self.valor = valor
        self.hijos = hijos or []

    def __repr__(self):
        if self.valor is not None:
            return f"{self.tipo}({self.valor})"
        return self.tipo

    def imprimir(self, nivel=0):
        indent = "  " * nivel
        if self.valor is not None:
            print(f"{indent}{self.tipo}: {self.valor}")
        else:
            print(f"{indent}{self.tipo}")
        for hijo in self.hijos:
            hijo.imprimir(nivel + 1)


class ParserLL:
    """
    Parser Recursivo Descendente LL(1)
    Implementa el analisis top-down con derivacion por la izquierda
    """

    def __init__(self, tokens):
        self.tokens = tokens
        self.pos = 0
        self.errores = []

    def actual(self):
        if self.pos < len(self.tokens):
            return self.tokens[self.pos]
        return self.tokens[-1]  # EOF

    def consumir(self, tipo_esperado):
        tok = self.actual()
        if tok.tipo == tipo_esperado:
            self.pos += 1
            return tok
        self.error(f"Se esperaba '{tipo_esperado}' pero se encontro '{tok.tipo}' ('{tok.valor}')")
        return None

    def error(self, mensaje):
        tok = self.actual()
        msg = f"Error sintactico en linea {tok.linea}, columna {tok.columna}: {mensaje}"
        self.errores.append(msg)
        # Recuperacion basica: avanzar al siguiente token
        self.pos += 1

    def parse(self):
        """Punto de entrada: E -> T E1"""
        ast = self.parse_E()
        if self.actual().tipo != 'EOF':
            self.error(f"Tokens inesperados al final: {self.actual()}")
        return ast, self.errores

    # E -> T E1
    def parse_E(self):
        nodo_t = self.parse_T()
        nodo_ep = self.parse_E1()
        if nodo_ep:
            return NodoAST('E', hijos=[nodo_t, nodo_ep])
        return nodo_t

    # E1 -> + T E1 | - T E1 | epsilon
    def parse_E1(self):
        tok = self.actual()
        if tok.tipo in ('PLUS', 'MINUS'):
            self.pos += 1
            nodo_t = self.parse_T()
            nodo_ep = self.parse_E1()
            if nodo_ep:
                return NodoAST('E1', valor=tok.valor, hijos=[nodo_t, nodo_ep])
            return NodoAST('E1', valor=tok.valor, hijos=[nodo_t])
        # epsilon - no consumimos token
        return None

    # T -> F T1
    def parse_T(self):
        nodo_f = self.parse_F()
        nodo_tp = self.parse_T1()
        if nodo_tp:
            return NodoAST('T', hijos=[nodo_f, nodo_tp])
        return nodo_f

    # T1 -> * F T1 | / F T1 | epsilon
    def parse_T1(self):
        tok = self.actual()
        if tok.tipo in ('MULT', 'DIV'):
            self.pos += 1
            nodo_f = self.parse_F()
            nodo_tp = self.parse_T1()
            if nodo_tp:
                return NodoAST('T1', valor=tok.valor, hijos=[nodo_f, nodo_tp])
            return NodoAST('T1', valor=tok.valor, hijos=[nodo_f])
        # epsilon
        return None

    # F -> ( E ) | NUM
    def parse_F(self):
        tok = self.actual()
        if tok.tipo == 'LPAREN':
            self.pos += 1
            nodo_e = self.parse_E()
            self.consumir('RPAREN')
            return NodoAST('F', valor='grupo', hijos=[nodo_e])
        elif tok.tipo == 'NUM':
            self.pos += 1
            return NodoAST('NUM', valor=tok.valor)
        else:
            self.error(f"Se esperaba numero o '(' pero se encontro '{tok.tipo}'")
            return NodoAST('ERROR')


def evaluar_ast(nodo):
    """Evalua el AST para obtener el resultado numerico"""
    if nodo.tipo == 'NUM':
        return nodo.valor

    if nodo.tipo in ('E', 'T') and len(nodo.hijos) == 1:
        return evaluar_ast(nodo.hijos[0])

    if nodo.tipo in ('E1', 'T1'):
        # Operador binario
        izq = evaluar_ast(nodo.hijos[0])
        if len(nodo.hijos) > 1 and nodo.hijos[1] is not None:
            der = evaluar_ast(nodo.hijos[1])
        else:
            return izq

        if nodo.valor == '+':
            return izq + der
        elif nodo.valor == '-':
            return izq - der
        elif nodo.valor == '*':
            return izq * der
        elif nodo.valor == '/':
            if der == 0:
                raise ZeroDivisionError("Division por cero")
            return izq / der

    if nodo.tipo == 'F' and nodo.valor == 'grupo':
        return evaluar_ast(nodo.hijos[0])

    if len(nodo.hijos) == 2:
        izq = evaluar_ast(nodo.hijos[0])
        der = evaluar_ast(nodo.hijos[1])
        if nodo.tipo == 'E':
            return der if isinstance(der, (int, float)) else izq
        return izq

    return 0


# ============================================
# DEMOSTRACION
# ============================================
if __name__ == "__main__":
    print("=" * 60)
    print("PARSER LL(1) - RECURSIVO DESCENDENTE")
    print("Lenguaje: Calculadora de Expresiones Aritmeticas")
    print("=" * 60)

    expresiones_prueba = [
        "3 + 5",
        "10 - 2 * 3",
        "(4 + 6) / 2",
        "8 / 2 + 3 * 2",
        "42",
        "(1 + 2) * (3 + 4)"
    ]

    for expr in expresiones_prueba:
        print(f"\n--- Entrada: '{expr}' ---")
        try:
            lexer = LexerLL(expr)
            tokens = lexer.tokenizar()
            print(f"Tokens: {tokens}")

            parser = ParserLL(tokens)
            ast, errores = parser.parse()

            if errores:
                print("Errores encontrados:")
                for err in errores:
                    print(f"  - {err}")
            else:
                print("AST generado:")
                ast.imprimir()
                try:
                    resultado = evaluar_ast(ast)
                    print(f"Resultado: {resultado}")
                except Exception as e:
                    print(f"Error de evaluacion: {e}")
        except Exception as e:
            print(f"Error: {e}")
