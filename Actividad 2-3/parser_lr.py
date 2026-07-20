
"""
PARSER LR(1) - TABLA-DRIVEN (Bottom-Up)
Lenguaje: Calculadora de Expresiones Aritmeticas
Autor: Generado para UNEG - Lenguaje y Compiladores 2026-I

Gramatica LR(1):
0. S1 -> S
1. S  -> E
2. E  -> E + T
3. E  -> E - T
4. E  -> T
5. T  -> T * F
6. T  -> T / F
7. T  -> F
8. F  -> ( E )
9. F  -> NUM
"""

from enum import Enum

class Accion(Enum):
    SHIFT = "shift"
    REDUCE = "reduce"
    ACCEPT = "accept"
    ERROR = "error"

class Token:
    def __init__(self, tipo, valor, linea=1, columna=1):
        self.tipo = tipo
        self.valor = valor
        self.linea = linea
        self.columna = columna

    def __repr__(self):
        return f"Token({self.tipo}, '{self.valor}')"

class LexerLR:
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
            if char in ' \t\n\r':
                self.avanzar()
                continue
            if char.isdigit():
                inicio = self.pos
                linea_inicio = self.linea
                col_inicio = self.columna
                while self.peek() is not None and self.peek().isdigit():
                    self.avanzar()
                valor = self.texto[inicio:self.pos]
                self.tokens.append(Token('NUM', int(valor), linea_inicio, col_inicio))
                continue
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
    def __init__(self, tipo, valor=None, hijos=None):
        self.tipo = tipo
        self.valor = valor
        self.hijos = hijos or []
        self.resultado = None

    def __repr__(self):
        if self.valor is not None:
            return f"{self.tipo}({self.valor})"
        return self.tipo

    def imprimir(self, nivel=0):
        indent = "  " * nivel
        res = f" = {self.resultado}" if self.resultado is not None else ""
        if self.valor is not None:
            print(f"{indent}{self.tipo}: {self.valor}{res}")
        else:
            print(f"{indent}{self.tipo}{res}")
        for hijo in self.hijos:
            hijo.imprimir(nivel + 1)


class ParserLR:
    """
    Parser LR(1) Tabla-Driven con tabla SLR(1) completa
    Construida manualmente verificando todos los estados
    """

    def __init__(self, tokens):
        self.tokens = tokens
        self.pos = 0
        self.pila = []
        self.nodos = []
        self.errores = []
        self.pasos = []

        # Tabla ACTION completa [estado][terminal]
        # Estados 0-11, con acciones shift/reduce/accept
        self.tabla_accion = {
            # I0: S' -> .S, S -> .E, E -> .E+T, E -> .E-T, E -> .T, T -> .T*F, T -> .T/F, T -> .F, F -> .(E), F -> .NUM
            0: {
                'NUM': (Accion.SHIFT, 5),
                'LPAREN': (Accion.SHIFT, 4),
            },
            # I1: S' -> S., E -> E.+T, E -> E.-T
            1: {
                'PLUS': (Accion.SHIFT, 6),
                'MINUS': (Accion.SHIFT, 7),
                'EOF': (Accion.ACCEPT, 0),
            },
            # I2: E -> T., T -> T.*F, T -> T./F
            2: {
                'PLUS': (Accion.REDUCE, 4),   # E -> T
                'MINUS': (Accion.REDUCE, 4),
                'MULT': (Accion.SHIFT, 8),
                'DIV': (Accion.SHIFT, 9),
                'RPAREN': (Accion.REDUCE, 4),
                'EOF': (Accion.REDUCE, 4),
            },
            # I3: T -> F.
            3: {
                'PLUS': (Accion.REDUCE, 7),   # T -> F
                'MINUS': (Accion.REDUCE, 7),
                'MULT': (Accion.REDUCE, 7),
                'DIV': (Accion.REDUCE, 7),
                'RPAREN': (Accion.REDUCE, 7),
                'EOF': (Accion.REDUCE, 7),
            },
            # I4: F -> (.E), E -> .E+T, E -> .E-T, E -> .T, T -> .T*F, T -> .T/F, T -> .F, F -> .(E), F -> .NUM
            4: {
                'NUM': (Accion.SHIFT, 5),
                'LPAREN': (Accion.SHIFT, 4),
            },
            # I5: F -> NUM.
            5: {
                'PLUS': (Accion.REDUCE, 9),   # F -> NUM
                'MINUS': (Accion.REDUCE, 9),
                'MULT': (Accion.REDUCE, 9),
                'DIV': (Accion.REDUCE, 9),
                'RPAREN': (Accion.REDUCE, 9),
                'EOF': (Accion.REDUCE, 9),
            },
            # I6: E -> E+.T, T -> .T*F, T -> .T/F, T -> .F, F -> .(E), F -> .NUM
            6: {
                'NUM': (Accion.SHIFT, 5),
                'LPAREN': (Accion.SHIFT, 4),
            },
            # I7: E -> E-.T, T -> .T*F, T -> .T/F, T -> .F, F -> .(E), F -> .NUM
            7: {
                'NUM': (Accion.SHIFT, 5),
                'LPAREN': (Accion.SHIFT, 4),
            },
            # I8: T -> T*.F, F -> .(E), F -> .NUM
            8: {
                'NUM': (Accion.SHIFT, 5),
                'LPAREN': (Accion.SHIFT, 4),
            },
            # I9: T -> T/.F, F -> .(E), F -> .NUM
            9: {
                'NUM': (Accion.SHIFT, 5),
                'LPAREN': (Accion.SHIFT, 4),
            },
            # I10: F -> (E.), E -> E.+T, E -> E.-T
            10: {
                'PLUS': (Accion.SHIFT, 6),
                'MINUS': (Accion.SHIFT, 7),
                'RPAREN': (Accion.SHIFT, 11),
            },
            # I11: F -> (E).
            11: {
                'PLUS': (Accion.REDUCE, 8),   # F -> (E)
                'MINUS': (Accion.REDUCE, 8),
                'MULT': (Accion.REDUCE, 8),
                'DIV': (Accion.REDUCE, 8),
                'RPAREN': (Accion.REDUCE, 8),
                'EOF': (Accion.REDUCE, 8),
            },
            # I12: E -> E+T., T -> T.*F, T -> T./F
            12: {
                'PLUS': (Accion.REDUCE, 2),   # E -> E+T
                'MINUS': (Accion.REDUCE, 2),
                'MULT': (Accion.SHIFT, 8),
                'DIV': (Accion.SHIFT, 9),
                'RPAREN': (Accion.REDUCE, 2),
                'EOF': (Accion.REDUCE, 2),
            },
            # I13: E -> E-T., T -> T.*F, T -> T./F
            13: {
                'PLUS': (Accion.REDUCE, 3),   # E -> E-T
                'MINUS': (Accion.REDUCE, 3),
                'MULT': (Accion.SHIFT, 8),
                'DIV': (Accion.SHIFT, 9),
                'RPAREN': (Accion.REDUCE, 3),
                'EOF': (Accion.REDUCE, 3),
            },
            # I14: T -> T*F.
            14: {
                'PLUS': (Accion.REDUCE, 5),   # T -> T*F
                'MINUS': (Accion.REDUCE, 5),
                'MULT': (Accion.REDUCE, 5),
                'DIV': (Accion.REDUCE, 5),
                'RPAREN': (Accion.REDUCE, 5),
                'EOF': (Accion.REDUCE, 5),
            },
            # I15: T -> T/F.
            15: {
                'PLUS': (Accion.REDUCE, 6),   # T -> T/F
                'MINUS': (Accion.REDUCE, 6),
                'MULT': (Accion.REDUCE, 6),
                'DIV': (Accion.REDUCE, 6),
                'RPAREN': (Accion.REDUCE, 6),
                'EOF': (Accion.REDUCE, 6),
            },
        }

        # Tabla GOTO completa [estado][no_terminal]
        self.tabla_goto = {
            0: {'S': 1, 'E': 1, 'T': 2, 'F': 3},
            4: {'E': 10, 'T': 2, 'F': 3},
            6: {'T': 12, 'F': 3},
            7: {'T': 13, 'F': 3},
            8: {'F': 14},
            9: {'F': 15},
        }

        # Reglas de produccion
        self.reglas = {
            1: ('S', 1, "S -> E"),
            2: ('E', 3, "E -> E + T"),
            3: ('E', 3, "E -> E - T"),
            4: ('E', 1, "E -> T"),
            5: ('T', 3, "T -> T * F"),
            6: ('T', 3, "T -> T / F"),
            7: ('T', 1, "T -> F"),
            8: ('F', 3, "F -> ( E )"),
            9: ('F', 1, "F -> NUM"),
        }

    def actual_token(self):
        if self.pos < len(self.tokens):
            return self.tokens[self.pos]
        return self.tokens[-1]

    def error(self, mensaje):
        tok = self.actual_token()
        msg = f"Error sintactico en linea {tok.linea}, columna {tok.columna}: {mensaje}"
        self.errores.append(msg)

    def parse(self):
        self.pila = [0]
        self.nodos = []

        while True:
            estado = self.pila[-1]
            token = self.actual_token()

            if estado not in self.tabla_accion or token.tipo not in self.tabla_accion[estado]:
                esperados = list(self.tabla_accion.get(estado, {}).keys())
                self.error(f"Token inesperado '{token.valor}'. Se esperaba uno de: {esperados}")
                self.pos += 1
                if token.tipo == 'EOF':
                    break
                continue

            accion, valor = self.tabla_accion[estado][token.tipo]

            self.pasos.append({
                'pila': list(self.pila),
                'token': token.tipo,
                'accion': accion.value,
                'valor': valor
            })

            if accion == Accion.SHIFT:
                self.pila.append(valor)
                nodo = NodoAST(token.tipo, valor=token.valor)
                if token.tipo == 'NUM':
                    nodo.resultado = token.valor
                self.nodos.append(nodo)
                self.pos += 1

            elif accion == Accion.REDUCE:
                lhs, num_rhs, desc = self.reglas[valor]

                nodos_hijos = []
                for _ in range(num_rhs):
                    self.pila.pop()
                    if self.nodos:
                        nodos_hijos.insert(0, self.nodos.pop())

                nodo_padre = NodoAST(lhs, hijos=nodos_hijos)

                # Evaluacion bottom-up
                if valor == 9:  # F -> NUM
                    nodo_padre.resultado = nodos_hijos[0].resultado
                elif valor == 7:  # T -> F
                    nodo_padre.resultado = nodos_hijos[0].resultado
                elif valor == 4:  # E -> T
                    nodo_padre.resultado = nodos_hijos[0].resultado
                elif valor in (2, 3):  # E -> E op T
                    izq = nodos_hijos[0].resultado
                    der = nodos_hijos[2].resultado
                    op = nodos_hijos[1].valor
                    if op == '+':
                        nodo_padre.resultado = izq + der
                    elif op == '-':
                        nodo_padre.resultado = izq - der
                elif valor in (5, 6):  # T -> T op F
                    izq = nodos_hijos[0].resultado
                    der = nodos_hijos[2].resultado
                    op = nodos_hijos[1].valor
                    if op == '*':
                        nodo_padre.resultado = izq * der
                    elif op == '/':
                        if der == 0:
                            raise ZeroDivisionError("Division por cero")
                        nodo_padre.resultado = izq / der
                elif valor == 8:  # F -> ( E )
                    nodo_padre.resultado = nodos_hijos[1].resultado

                self.nodos.append(nodo_padre)

                nuevo_estado = self.pila[-1]
                if nuevo_estado in self.tabla_goto and lhs in self.tabla_goto[nuevo_estado]:
                    self.pila.append(self.tabla_goto[nuevo_estado][lhs])
                else:
                    self.error(f"No hay transicion GOTO para '{lhs}' desde estado {nuevo_estado}")
                    break

            elif accion == Accion.ACCEPT:
                ast = self.nodos[-1] if self.nodos else None
                return ast, self.errores, self.pasos

            elif accion == Accion.ERROR:
                self.error(f"Error en estado {estado} con token {token.tipo}")
                break

        ast = self.nodos[-1] if self.nodos else None
        return ast, self.errores, self.pasos


if __name__ == "__main__":
    print("=" * 60)
    print("PARSER LR(1) - TABLA-DRIVEN (BOTTOM-UP)")
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
            lexer = LexerLR(expr)
            tokens = lexer.tokenizar()
            print(f"Tokens: {tokens}")

            parser = ParserLR(tokens)
            ast, errores, pasos = parser.parse()

            if errores:
                print("Errores encontrados:")
                for err in errores:
                    print(f"  - {err}")
            else:
                print(f"Numero de pasos de analisis: {len(pasos)}")
                print("AST generado (con evaluacion bottom-up):")
                ast.imprimir()
                if ast and ast.resultado is not None:
                    print(f"Resultado: {ast.resultado}")

        except Exception as e:
            print(f"Error: {e}")
