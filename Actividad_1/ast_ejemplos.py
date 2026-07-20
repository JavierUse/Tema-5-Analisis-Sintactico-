"""
Actividad 1 - Tema 5: Analisis Sintactico
Arbol de Sintaxis Abstracta (AST): implementacion de dos ejemplos.

Ejemplo 1: Expresion aritmetica
    Gramatica (GLC):
        E -> E + T | E - T | T
        T -> T * F | T / F | F
        F -> ( E ) | NUM
    (reescrita sin recursion izquierda para el parser recursivo descendente)
        E  -> T E'
        E' -> + T E' | - T E' | epsilon
        T  -> F T'
        T' -> * F T' | / F T' | epsilon
        F  -> ( E ) | NUM

Ejemplo 2: Sentencia condicional (if-else) de un mini-lenguaje tipo C
    Gramatica (GLC):
        Stmt   -> IfStmt | Assign
        IfStmt -> if ( Cond ) { Assign } else { Assign }
        Assign -> ID = Expr ;
        Cond   -> Expr OP Expr
        Expr   -> ID | NUM | Expr + Expr
        OP     -> > | < | == | >= | <=

Autor: Actividad Lenguaje y Compiladores - UNEG
"""

from __future__ import annotations
import re
import sys
from dataclasses import dataclass, field
from typing import List, Optional

try:
    import graphviz
    HAS_GRAPHVIZ = True
except ImportError:
    HAS_GRAPHVIZ = False


# =====================================================================
# 1. DEFINICION GENERICA DE NODO DE AST
# =====================================================================
class ASTNode:
    """
    Clase base de todo nodo del Arbol de Sintaxis Abstracta.
    Un AST, a diferencia de un arbol de analisis (parse tree), NO
    conserva simbolos superfluos de la gramatica (parentesis, punto y
    coma, no-terminales intermedios); solo retiene la informacion
    semanticamente relevante para las siguientes fases del compilador.
    """

    def children(self) -> List["ASTNode"]:
        """Devuelve la lista de nodos hijos (para recorrido/impresion)."""
        return []

    def label(self) -> str:
        """Etiqueta textual del nodo (se muestra en el arbol)."""
        return self.__class__.__name__

    # ---------- utilidades de presentacion ----------
    def pretty(self, prefix: str = "", is_last: bool = True, is_root: bool = True) -> str:
        """Devuelve una representacion textual en forma de arbol (estilo 'tree')."""
        lines = []
        connector = "" if is_root else ("`-- " if is_last else "|-- ")
        lines.append(f"{prefix}{connector}{self.label()}")
        new_prefix = prefix if is_root else prefix + ("    " if is_last else "|   ")
        kids = self.children()
        for i, child in enumerate(kids):
            lines.append(child.pretty(new_prefix, i == len(kids) - 1, False))
        return "\n".join(lines)

    def to_graphviz(self, g: "graphviz.Digraph", counter: List[int]) -> str:
        """Construye recursivamente el grafo graphviz y devuelve el id del nodo."""
        node_id = f"n{counter[0]}"
        counter[0] += 1
        g.node(node_id, self.label(), shape="box", style="rounded,filled",
               fillcolor="#EAF2FF", fontname="Consolas")
        for child in self.children():
            child_id = child.to_graphviz(g, counter)
            g.edge(node_id, child_id)
        return node_id

    def render(self, filename: str, fmt: str = "png"):
        if not HAS_GRAPHVIZ:
            raise RuntimeError("graphviz no disponible")
        g = graphviz.Digraph(filename, format=fmt)
        g.attr("graph", rankdir="TB", bgcolor="white")
        self.to_graphviz(g, [0])
        g.render(filename, cleanup=True)


# =====================================================================
# 2. NODOS ESPECIFICOS - EJEMPLO 1: EXPRESIONES ARITMETICAS
# =====================================================================
@dataclass
class Num(ASTNode):
    value: float

    def label(self) -> str:
        return f"Num({self.value})"


@dataclass
class BinOp(ASTNode):
    op: str
    left: ASTNode
    right: ASTNode

    def label(self) -> str:
        return f"BinOp('{self.op}')"

    def children(self) -> List[ASTNode]:
        return [self.left, self.right]

    def eval(self):
        l = self.left.eval() if isinstance(self.left, (BinOp, Num)) else None
        r = self.right.eval() if isinstance(self.right, (BinOp, Num)) else None
        return {"+": l + r, "-": l - r, "*": l * r, "/": l / r}[self.op]


# permitir eval() tambien sobre Num
def _num_eval(self):
    return self.value
Num.eval = _num_eval


# ------------------- Lexer para expresiones -------------------
TOKEN_SPEC_EXPR = [
    ("NUM", r"\d+(\.\d+)?"),
    ("OP", r"[+\-*/]"),
    ("LPAREN", r"\("),
    ("RPAREN", r"\)"),
    ("SKIP", r"[ \t]+"),
]
TOKEN_RE_EXPR = re.compile("|".join(f"(?P<{n}>{p})" for n, p in TOKEN_SPEC_EXPR))


def tokenize_expr(text: str):
    tokens = []
    for m in TOKEN_RE_EXPR.finditer(text):
        kind = m.lastgroup
        val = m.group()
        if kind == "SKIP":
            continue
        tokens.append((kind, val))
    tokens.append(("EOF", ""))
    return tokens


class ExprParser:
    """
    Parser recursivo descendente (LL(1)) para expresiones aritmeticas.
    Implementa la gramatica sin recursion izquierda:
        E  -> T E'
        E' -> + T E' | - T E' | epsilon
        T  -> F T'
        T' -> * F T' | / F T' | epsilon
        F  -> ( E ) | NUM
    """

    def __init__(self, text: str):
        self.tokens = tokenize_expr(text)
        self.pos = 0

    def peek(self):
        return self.tokens[self.pos]

    def advance(self):
        tok = self.tokens[self.pos]
        self.pos += 1
        return tok

    def expect(self, kind):
        tok = self.peek()
        if tok[0] != kind:
            raise SyntaxError(f"Se esperaba {kind}, se encontro {tok}")
        return self.advance()

    def parse(self) -> ASTNode:
        node = self.parse_E()
        self.expect("EOF")
        return node

    def parse_E(self) -> ASTNode:
        node = self.parse_T()
        while self.peek()[0] == "OP" and self.peek()[1] in ("+", "-"):
            op = self.advance()[1]
            right = self.parse_T()
            node = BinOp(op, node, right)
        return node

    def parse_T(self) -> ASTNode:
        node = self.parse_F()
        while self.peek()[0] == "OP" and self.peek()[1] in ("*", "/"):
            op = self.advance()[1]
            right = self.parse_F()
            node = BinOp(op, node, right)
        return node

    def parse_F(self) -> ASTNode:
        tok = self.peek()
        if tok[0] == "NUM":
            self.advance()
            return Num(float(tok[1]) if "." in tok[1] else int(tok[1]))
        if tok[0] == "LPAREN":
            self.advance()
            node = self.parse_E()
            self.expect("RPAREN")
            return node
        raise SyntaxError(f"Token inesperado: {tok}")


# =====================================================================
# 3. NODOS ESPECIFICOS - EJEMPLO 2: SENTENCIA IF-ELSE
# =====================================================================
@dataclass
class Ident(ASTNode):
    name: str

    def label(self) -> str:
        return f"Id({self.name})"


@dataclass
class Literal(ASTNode):
    value: str

    def label(self) -> str:
        return f"Num({self.value})"


@dataclass
class Assign(ASTNode):
    target: Ident
    expr: ASTNode

    def label(self) -> str:
        return "Assign(=)"

    def children(self) -> List[ASTNode]:
        return [self.target, self.expr]


@dataclass
class Condition(ASTNode):
    op: str
    left: ASTNode
    right: ASTNode

    def label(self) -> str:
        return f"Cond('{self.op}')"

    def children(self) -> List[ASTNode]:
        return [self.left, self.right]


@dataclass
class IfElse(ASTNode):
    condition: Condition
    then_branch: ASTNode
    else_branch: ASTNode

    def label(self) -> str:
        return "If"

    def children(self) -> List[ASTNode]:
        return [self.condition, self.then_branch, self.else_branch]


# ------------------- Lexer para sentencia if -------------------
TOKEN_SPEC_STMT = [
    ("IF", r"\bif\b"),
    ("ELSE", r"\belse\b"),
    ("NUM", r"\d+(\.\d+)?"),
    ("ID", r"[A-Za-z_][A-Za-z0-9_]*"),
    ("OP", r"==|>=|<=|[+\-*/><]"),
    ("ASSIGN", r"="),
    ("LPAREN", r"\("),
    ("RPAREN", r"\)"),
    ("LBRACE", r"\{"),
    ("RBRACE", r"\}"),
    ("SEMI", r";"),
    ("SKIP", r"[ \t\n]+"),
]
TOKEN_RE_STMT = re.compile("|".join(f"(?P<{n}>{p})" for n, p in TOKEN_SPEC_STMT))


def tokenize_stmt(text: str):
    tokens = []
    for m in TOKEN_RE_STMT.finditer(text):
        kind = m.lastgroup
        val = m.group()
        if kind == "SKIP":
            continue
        tokens.append((kind, val))
    tokens.append(("EOF", ""))
    return tokens


class StmtParser:
    """
    Parser recursivo descendente para:
        IfStmt -> if ( Expr OP Expr ) { Assign } else { Assign }
        Assign -> ID = Expr ;
        Expr   -> ID | NUM | Expr + Expr   (asociativo izquierdo simple)
    """

    def __init__(self, text: str):
        self.tokens = tokenize_stmt(text)
        self.pos = 0

    def peek(self):
        return self.tokens[self.pos]

    def advance(self):
        tok = self.tokens[self.pos]
        self.pos += 1
        return tok

    def expect(self, kind, val=None):
        tok = self.peek()
        if tok[0] != kind or (val is not None and tok[1] != val):
            raise SyntaxError(f"Se esperaba {kind} {val or ''}, se encontro {tok}")
        return self.advance()

    def parse(self) -> ASTNode:
        node = self.parse_if()
        self.expect("EOF")
        return node

    def parse_if(self) -> IfElse:
        self.expect("IF", "if")
        self.expect("LPAREN")
        left = self.parse_expr()
        op = self.expect("OP")[1]
        right = self.parse_expr()
        cond = Condition(op, left, right)
        self.expect("RPAREN")
        self.expect("LBRACE")
        then_branch = self.parse_assign()
        self.expect("RBRACE")
        self.expect("ELSE", "else")
        self.expect("LBRACE")
        else_branch = self.parse_assign()
        self.expect("RBRACE")
        return IfElse(cond, then_branch, else_branch)

    def parse_assign(self) -> Assign:
        ident = self.expect("ID")[1]
        self.expect("ASSIGN")
        expr = self.parse_expr()
        self.expect("SEMI")
        return Assign(Ident(ident), expr)

    def parse_expr(self) -> ASTNode:
        node = self.parse_atom()
        while self.peek()[0] == "OP" and self.peek()[1] == "+":
            self.advance()
            right = self.parse_atom()
            node = Condition("+", node, right)  # reutilizamos nodo binario generico
        return node

    def parse_atom(self) -> ASTNode:
        tok = self.peek()
        if tok[0] == "NUM":
            self.advance()
            return Literal(tok[1])
        if tok[0] == "ID":
            self.advance()
            return Ident(tok[1])
        raise SyntaxError(f"Token inesperado: {tok}")


# =====================================================================
# 4. PROGRAMA PRINCIPAL: construye y muestra ambos AST
# =====================================================================
def main():
    print("=" * 70)
    print("EJEMPLO 1: AST de una expresion aritmetica")
    print("=" * 70)
    entrada1 = "3 + 4 * (2 - 1)"
    print(f"Entrada : {entrada1}")
    ast1 = ExprParser(entrada1).parse()
    print("AST (forma de arbol):")
    print(ast1.pretty())
    print(f"Resultado de evaluar el AST -> {ast1.eval()}")
    if HAS_GRAPHVIZ:
        ast1.render("/home/claude/ast_activity/ast_ejemplo1")
        print("Diagrama guardado en ast_ejemplo1.png")

    print()
    print("=" * 70)
    print("EJEMPLO 2: AST de una sentencia if-else")
    print("=" * 70)
    entrada2 = "if (x > 3) { y = x + 1; } else { y = 0; }"
    print(f"Entrada : {entrada2}")
    ast2 = StmtParser(entrada2).parse()
    print("AST (forma de arbol):")
    print(ast2.pretty())
    if HAS_GRAPHVIZ:
        ast2.render("/home/claude/ast_activity/ast_ejemplo2")
        print("Diagrama guardado en ast_ejemplo2.png")


if __name__ == "__main__":
    main()
