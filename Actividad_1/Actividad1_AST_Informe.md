Elaborado: Jesus Baez CI:26753871

**TEMA 5: ANÁLISIS SINTÁCTICO**

**Informe de Investigación — Actividad 1**

*Árbol de Sintaxis Abstracta (AST)*

Definición, características, ejemplos e implementación


# **1. Introducción**

Dentro de las fases del compilador, el análisis sintáctico (parser) recibe la secuencia de tokens producida por el analizador léxico y valida que cumpla con las reglas de una gramática libre de contexto (GLC). Como resultado de este proceso, el parser no solo determina si la entrada es válida, sino que construye una representación intermedia que las siguientes fases (análisis semántico, optimización y generación de código) utilizarán: el Árbol de Sintaxis Abstracta (AST). Este informe desarrolla la Actividad 1 del Tema 5: se define el AST, se explican sus características principales, se presentan dos ejemplos de entrada y se implementa, en Python, un lexer y un parser recursivo descendente capaz de construir el AST correspondiente a cada ejemplo.

# **2. Árbol de Sintaxis Abstracta (AST)**

## **2.1 Definición**

Un Árbol de Sintaxis Abstracta (Abstract Syntax Tree, AST) es una estructura de datos jerárquica y en forma de árbol que representa la estructura sintáctica de un programa fuente, conservando únicamente los elementos que tienen significado semántico y descartando los detalles puramente sintácticos de la gramática concreta (paréntesis de agrupación, punto y coma, palabras reservadas usadas solo como delimitadores, no-terminales intermedios introducidos para resolver la precedencia o eliminar recursión izquierda, etc.).

Cada **nodo interno** del AST representa un operador, una construcción del lenguaje (una asignación, una sentencia **if**, un bucle, la declaración de una función) o un constructor sintáctico, mientras que cada **nodo hoja** representa un operando: un identificador, una constante numérica, una cadena, etc. El AST es la salida natural del analizador sintáctico y la entrada natural del analizador semántico.

## **2.2 Características principales**

* Abstracción: omite información redundante de la derivación (paréntesis, delimitadores, no-terminales auxiliares como E' o T' usados para eliminar recursión izquierda); solo se conserva lo necesario para reconstruir el significado del programa.
* Jerarquía y precedencia implícita: la estructura del árbol codifica por sí sola la precedencia y asociatividad de los operadores; no se requieren paréntesis para saber qué subexpresión se evalúa primero (la subexpresión más profunda se evalúa antes).
* Nodos tipados: cada nodo corresponde a una construcción semántica concreta del lenguaje (BinOp, Assign, If, Ident, Num, etc.), lo que facilita recorridos (visitor pattern) durante el análisis semántico y la generación de código.
* Compacidad: en comparación con el árbol de análisis o parse tree (que refleja cada paso de la derivación de la gramática), el AST es considerablemente más pequeño y legible.
* Independencia de la gramática concreta: distintas gramáticas (o distintas formas de escribir la misma gramática, p. ej. eliminando recursión izquierda) pueden producir el mismo AST para una misma entrada.
* Base para fases posteriores: sirve de entrada al chequeo de tipos, la resolución de ámbitos, la optimización (eliminación de nodos redundantes, plegado de constantes) y la generación de código intermedio u objeto.

## **2.3 AST vs. árbol de análisis (parse tree)**

Es importante distinguir el AST del árbol de análisis o parse tree. El parse tree (o árbol de derivación) refleja fielmente cada producción de la gramática aplicada durante la derivación, incluyendo terminales sintácticos sin significado semántico propio (paréntesis, comas, punto y coma) y no-terminales auxiliares. El AST, en cambio, es una versión depurada y abstracta de ese árbol: se conservan los operadores y operandos, pero se eliminan los símbolos que solo sirven para guiar el análisis. Por ejemplo, para la expresión (2 + 3), el parse tree contendría nodos para “(” y “)”, mientras que el AST solo contendría el nodo BinOp('+') con sus dos operandos.

| **Aspecto** | **Árbol de análisis (Parse Tree)** | **Árbol de Sintaxis Abstracta (AST)** |
| --- | --- | --- |
| Nivel de detalle | Refleja cada producción de la gramática | Solo retiene información semánticamente relevante |
| Tamaño | Grande (incluye no-terminales y delimitadores) | Compacto |
| Uso típico | Depuración del propio parser | Entrada para análisis semántico, optimización y generación de código |
| Dependencia de la gramática | Alta (cambia si la gramática se reescribe) | Baja (varias gramáticas equivalentes generan el mismo AST) |

# **3. Ejemplos de entrada y construcción del AST**

A continuación se presentan dos ejemplos de entrada y el AST correspondiente. Para cada uno se muestra la gramática (GLC) utilizada, la entrada concreta, el AST resultante (representación textual y diagrama) y un fragmento del código Python que lo construye. La implementación completa se incluye en la Sección 4 y en el archivo anexo ast\_ejemplos.py.

## **3.1 Ejemplo 1 — Expresión aritmética**

Se utiliza la gramática clásica de expresiones aritméticas con suma, resta, multiplicación, división y agrupación mediante paréntesis, reescrita para eliminar la recursión izquierda y permitir un análisis descendente LL(1):

E -> T E'

E' -> + T E' | - T E' | epsilon

T -> F T'

T' -> \* F T' | / F T' | epsilon

F -> ( E ) | NUM

Entrada de prueba:

3 + 4 \* (2 - 1)

Al aplicar la precedencia habitual (la multiplicación y la división se agrupan antes que la suma y la resta, y el paréntesis fuerza la evaluación de “2 - 1” primero), el AST resultante es el siguiente:


*AST de la expresión 3 + 4 \* (2 - 1)*

Nótese que el árbol no contiene nodos para los paréntesis: la jerarquía por sí sola (el nodo BinOp('\*') como hijo derecho de la raíz, y BinOp('-') como hijo derecho de este) ya codifica que “4 \* (2 - 1)” se evalúa como una unidad y que “2 - 1” se evalúa antes que la multiplicación.

## **3.2 Ejemplo 2 — Sentencia condicional (if / else)**

El segundo ejemplo corresponde a una sentencia condicional de un mini-lenguaje tipo C, con una condición relacional y una asignación en cada rama:

IfStmt -> if ( Expr OP Expr ) { Assign } else { Assign }

Assign -> ID = Expr ;

Expr -> Atom + Expr | Atom

Atom -> ID | NUM

OP -> > | < | == | >= | <=

Entrada de prueba:

if (x > 3) { y = x + 1; } else { y = 0; }

El AST agrupa la construcción en tres partes claramente diferenciadas —condición, rama verdadera y rama falsa— y ya no conserva los símbolos “if”, “(”, “)”, “{”, “}” ni “;”, que solo cumplieron su función durante el análisis sintáctico:


*AST de la sentencia if (x > 3) { y = x + 1; } else { y = 0; }*

# **4. Implementación**

La implementación se realizó en Python 3 y consta de tres partes: (1) una clase base ASTNode común a ambos ejemplos, con métodos para imprimir el árbol en forma textual y para exportarlo como diagrama mediante la librería Graphviz; (2) un lexer basado en expresiones regulares y un parser recursivo descendente (LL(1)) para expresiones aritméticas (Ejemplo 1); y (3) un lexer y un parser recursivo descendente para la sentencia if/else (Ejemplo 2). Ambos parsers siguen el mismo principio: cada método del parser corresponde a un no-terminal de la gramática y, al reconocer una producción, construye y devuelve el nodo de AST correspondiente en lugar de un nodo de árbol de análisis genérico.

## **4.1 Clase base del nodo de AST**

class ASTNode:

def children(self) -> List["ASTNode"]:

return []

def label(self) -> str:

return self.\_\_class\_\_.\_\_name\_\_

def pretty(self, prefix="", is\_last=True, is\_root=True) -> str:

# imprime el arbol con conectores tipo "|--" y "`--"

...

## **4.2 Parser recursivo descendente — Ejemplo 1 (expresiones)**

El núcleo del parser recorre la gramática sin recursión izquierda: parse\_E maneja + y -, parse\_T maneja \* y /, y parse\_F resuelve un número o una subexpresión entre paréntesis. Cada función retorna directamente un nodo BinOp o Num:

def parse\_E(self) -> ASTNode:

node = self.parse\_T()

while self.peek()[0] == "OP" and self.peek()[1] in ("+", "-"):

op = self.advance()[1]

right = self.parse\_T()

node = BinOp(op, node, right) # construccion del nodo AST

return node

def parse\_F(self) -> ASTNode:

tok = self.peek()

if tok[0] == "NUM":

self.advance()

return Num(float(tok[1]) if "." in tok[1] else int(tok[1]))

if tok[0] == "LPAREN":

self.advance()

node = self.parse\_E()

self.expect("RPAREN") # el parentesis se consume

return node # pero NO se agrega al AST

## **4.3 Parser recursivo descendente — Ejemplo 2 (if / else)**

De forma análoga, parse\_if reconoce la condición y las dos ramas, construyendo un único nodo IfElse; los símbolos de puntuación (paréntesis, llaves, punto y coma) se consumen con expect() pero nunca se incorporan al árbol:

def parse\_if(self) -> IfElse:

self.expect("IF", "if")

self.expect("LPAREN")

left = self.parse\_expr()

op = self.expect("OP")[1]

right = self.parse\_expr()

cond = Condition(op, left, right)

self.expect("RPAREN")

self.expect("LBRACE")

then\_branch = self.parse\_assign()

self.expect("RBRACE")

self.expect("ELSE", "else")

self.expect("LBRACE")

else\_branch = self.parse\_assign()

self.expect("RBRACE")

return IfElse(cond, then\_branch, else\_branch)

## **4.4 Ejecución y salida del programa**

Al ejecutar python3 ast\_ejemplos.py se procesan ambos ejemplos y se imprime el AST en forma de árbol textual (además de generarse el diagrama gráfico mostrado en la Sección 3). La salida obtenida fue la siguiente:

Entrada : 3 + 4 \* (2 - 1)

AST (forma de arbol):

BinOp('+')

|-- Num(3)

`-- BinOp('\*')

|-- Num(4)

`-- BinOp('-')

|-- Num(2)

`-- Num(1)

Resultado de evaluar el AST -> 7

Entrada : if (x > 3) { y = x + 1; } else { y = 0; }

AST (forma de arbol):

If

|-- Cond('>')

| |-- Id(x)

| `-- Num(3)

|-- Assign(=)

| |-- Id(y)

| `-- Cond('+')

| |-- Id(x)

| `-- Num(1)

`-- Assign(=)

|-- Id(y)

`-- Num(0)

# **5. Conclusiones**

* El AST es la estructura central que conecta el análisis sintáctico con el resto del pipeline del compilador: es compacto, tipado y libre de ruido sintáctico, lo que lo hace apto para chequeo de tipos, optimización y generación de código.
* Un mismo AST puede construirse a partir de gramáticas escritas de forma distinta (por ejemplo, con o sin eliminación de recursión izquierda), siempre que ambas reconozcan el mismo lenguaje; el AST abstrae esas diferencias de la gramática concreta.
* Un parser recursivo descendente LL(1) es una forma directa y didáctica de construir un AST: basta con que cada función que reconoce un no-terminal retorne el nodo correspondiente en lugar de únicamente validar la entrada.
* Los símbolos puramente delimitadores (paréntesis, llaves, punto y coma, la propia palabra reservada “if”) se consumen durante el análisis pero deliberadamente no se agregan al árbol, lo cual es precisamente lo que distingue a un AST de un árbol de análisis (parse tree) completo.

# **6. Referencias**

*Aho, A. V., Lam, M. S., Sethi, R., & Ullman, J. D. (2006). Compilers: Principles, Techniques, and Tools (2nd ed.). Addison-Wesley.*

*Parr, T. (2013). The Definitive ANTLR 4 Reference. Pragmatic Bookshelf.*

*Grune, D., & Jacobs, C. J. H. (2008). Parsing Techniques: A Practical Guide (2nd ed.). Springer.*

*Márquez, F. (2026). Tema 5: Análisis Sintáctico. UNEG — Lenguaje y Compiladores, Trimestre 2026-I.*

# **Anexo A. Código fuente completo (ast\_ejemplos.py)**

Se adjunta a continuación el código fuente completo utilizado para generar ambos ejemplos (también disponible como archivo independiente ast\_ejemplos.py).

"""

Actividad 1 - Tema 5: Analisis Sintactico

Arbol de Sintaxis Abstracta (AST): implementacion de dos ejemplos.

Ejemplo 1: Expresion aritmetica

Gramatica (GLC):

E -> E + T | E - T | T

T -> T \* F | T / F | F

F -> ( E ) | NUM

(reescrita sin recursion izquierda para el parser recursivo descendente)

E -> T E'

E' -> + T E' | - T E' | epsilon

T -> F T'

T' -> \* F T' | / F T' | epsilon

F -> ( E ) | NUM

Ejemplo 2: Sentencia condicional (if-else) de un mini-lenguaje tipo C

Gramatica (GLC):

Stmt -> IfStmt | Assign

IfStmt -> if ( Cond ) { Assign } else { Assign }

Assign -> ID = Expr ;

Cond -> Expr OP Expr

Expr -> ID | NUM | Expr + Expr

OP -> > | < | == | >= | <=

Autor: Actividad Lenguaje y Compiladores - UNEG

"""

from \_\_future\_\_ import annotations

import re

import sys

from dataclasses import dataclass, field

from typing import List, Optional

try:

import graphviz

HAS\_GRAPHVIZ = True

except ImportError:

HAS\_GRAPHVIZ = False

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

return self.\_\_class\_\_.\_\_name\_\_

# ---------- utilidades de presentacion ----------

def pretty(self, prefix: str = "", is\_last: bool = True, is\_root: bool = True) -> str:

"""Devuelve una representacion textual en forma de arbol (estilo 'tree')."""

lines = []

connector = "" if is\_root else ("`-- " if is\_last else "|-- ")

lines.append(f"{prefix}{connector}{self.label()}")

new\_prefix = prefix if is\_root else prefix + (" " if is\_last else "| ")

kids = self.children()

for i, child in enumerate(kids):

lines.append(child.pretty(new\_prefix, i == len(kids) - 1, False))

return "\n".join(lines)

def to\_graphviz(self, g: "graphviz.Digraph", counter: List[int]) -> str:

"""Construye recursivamente el grafo graphviz y devuelve el id del nodo."""

node\_id = f"n{counter[0]}"

counter[0] += 1

g.node(node\_id, self.label(), shape="box", style="rounded,filled",

fillcolor="#EAF2FF", fontname="Consolas")

for child in self.children():

child\_id = child.to\_graphviz(g, counter)

g.edge(node\_id, child\_id)

return node\_id

def render(self, filename: str, fmt: str = "png"):

if not HAS\_GRAPHVIZ:

raise RuntimeError("graphviz no disponible")

g = graphviz.Digraph(filename, format=fmt)

g.attr("graph", rankdir="TB", bgcolor="white")

self.to\_graphviz(g, [0])

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

return {"+": l + r, "-": l - r, "\*": l \* r, "/": l / r}[self.op]

# permitir eval() tambien sobre Num

def \_num\_eval(self):

return self.value

Num.eval = \_num\_eval

# ------------------- Lexer para expresiones -------------------

TOKEN\_SPEC\_EXPR = [

("NUM", r"\d+(\.\d+)?"),

("OP", r"[+\-\*/]"),

("LPAREN", r"\("),

("RPAREN", r"\)"),

("SKIP", r"[ \t]+"),

]

TOKEN\_RE\_EXPR = re.compile("|".join(f"(?P<{n}>{p})" for n, p in TOKEN\_SPEC\_EXPR))

def tokenize\_expr(text: str):

tokens = []

for m in TOKEN\_RE\_EXPR.finditer(text):

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

E -> T E'

E' -> + T E' | - T E' | epsilon

T -> F T'

T' -> \* F T' | / F T' | epsilon

F -> ( E ) | NUM

"""

def \_\_init\_\_(self, text: str):

self.tokens = tokenize\_expr(text)

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

node = self.parse\_E()

self.expect("EOF")

return node

def parse\_E(self) -> ASTNode:

node = self.parse\_T()

while self.peek()[0] == "OP" and self.peek()[1] in ("+", "-"):

op = self.advance()[1]

right = self.parse\_T()

node = BinOp(op, node, right)

return node

def parse\_T(self) -> ASTNode:

node = self.parse\_F()

while self.peek()[0] == "OP" and self.peek()[1] in ("\*", "/"):

op = self.advance()[1]

right = self.parse\_F()

node = BinOp(op, node, right)

return node

def parse\_F(self) -> ASTNode:

tok = self.peek()

if tok[0] == "NUM":

self.advance()

return Num(float(tok[1]) if "." in tok[1] else int(tok[1]))

if tok[0] == "LPAREN":

self.advance()

node = self.parse\_E()

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

then\_branch: ASTNode

else\_branch: ASTNode

def label(self) -> str:

return "If"

def children(self) -> List[ASTNode]:

return [self.condition, self.then\_branch, self.else\_branch]

# ------------------- Lexer para sentencia if -------------------

TOKEN\_SPEC\_STMT = [

("IF", r"\bif\b"),

("ELSE", r"\belse\b"),

("NUM", r"\d+(\.\d+)?"),

("ID", r"[A-Za-z\_][A-Za-z0-9\_]\*"),

("OP", r"==|>=|<=|[+\-\*/><]"),

("ASSIGN", r"="),

("LPAREN", r"\("),

("RPAREN", r"\)"),

("LBRACE", r"\{"),

("RBRACE", r"\}"),

("SEMI", r";"),

("SKIP", r"[ \t\n]+"),

]

TOKEN\_RE\_STMT = re.compile("|".join(f"(?P<{n}>{p})" for n, p in TOKEN\_SPEC\_STMT))

def tokenize\_stmt(text: str):

tokens = []

for m in TOKEN\_RE\_STMT.finditer(text):

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

Expr -> ID | NUM | Expr + Expr (asociativo izquierdo simple)

"""

def \_\_init\_\_(self, text: str):

self.tokens = tokenize\_stmt(text)

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

node = self.parse\_if()

self.expect("EOF")

return node

def parse\_if(self) -> IfElse:

self.expect("IF", "if")

self.expect("LPAREN")

left = self.parse\_expr()

op = self.expect("OP")[1]

right = self.parse\_expr()

cond = Condition(op, left, right)

self.expect("RPAREN")

self.expect("LBRACE")

then\_branch = self.parse\_assign()

self.expect("RBRACE")

self.expect("ELSE", "else")

self.expect("LBRACE")

else\_branch = self.parse\_assign()

self.expect("RBRACE")

return IfElse(cond, then\_branch, else\_branch)

def parse\_assign(self) -> Assign:

ident = self.expect("ID")[1]

self.expect("ASSIGN")

expr = self.parse\_expr()

self.expect("SEMI")

return Assign(Ident(ident), expr)

def parse\_expr(self) -> ASTNode:

node = self.parse\_atom()

while self.peek()[0] == "OP" and self.peek()[1] == "+":

self.advance()

right = self.parse\_atom()

node = Condition("+", node, right) # reutilizamos nodo binario generico

return node

def parse\_atom(self) -> ASTNode:

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

print("=" \* 70)

print("EJEMPLO 1: AST de una expresion aritmetica")

print("=" \* 70)

entrada1 = "3 + 4 \* (2 - 1)"

print(f"Entrada : {entrada1}")

ast1 = ExprParser(entrada1).parse()

print("AST (forma de arbol):")

print(ast1.pretty())

print(f"Resultado de evaluar el AST -> {ast1.eval()}")

if HAS\_GRAPHVIZ:

ast1.render("/home/claude/ast\_activity/ast\_ejemplo1")

print("Diagrama guardado en ast\_ejemplo1.png")

print()

print("=" \* 70)

print("EJEMPLO 2: AST de una sentencia if-else")

print("=" \* 70)

entrada2 = "if (x > 3) { y = x + 1; } else { y = 0; }"

print(f"Entrada : {entrada2}")

ast2 = StmtParser(entrada2).parse()

print("AST (forma de arbol):")

print(ast2.pretty())

if HAS\_GRAPHVIZ:

ast2.render("/home/claude/ast\_activity/ast\_ejemplo2")

print("Diagrama guardado en ast\_ejemplo2.png")

if \_\_name\_\_ == "\_\_main\_\_":

main()