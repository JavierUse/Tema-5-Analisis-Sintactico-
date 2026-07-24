import importlib.util
import runpy
import types
import sys

def load_module_from_path(name, path):
    module = types.ModuleType(name)
    module.__file__ = path
    with open(path, 'r', encoding='utf-8') as f:
        code = f.read()
    exec(compile(code, path, 'exec'), module.__dict__)
    sys.modules[name] = module
    return module

# Cargar módulos desde archivos
load_module_from_path('constructor_ast', 'constructor_ast.py')
load_module_from_path('analizador_lexico', 'analizador_lexico.py')
load_module_from_path('analizador_sintactico', 'analizador_sintactico.py')

from analizador_lexico import LexerHibrido, ListaSugerencias
from analizador_sintactico import ParserRecursivo

codigo_prueba = 'pront $x=5$; if $x>3~prnt(x) else prnt("no")'

lexer = LexerHibrido(codigo_prueba)
lexer.sugerencias_ia = ListaSugerencias()
tokens, sugerencias_lexer = lexer.tokenizar()

print('--- TOKENS CORREGIDOS ---')
for t in tokens:
    print(t)
print()

parser = ParserRecursivo(tokens)
ast_nodos, sugerencias_parser = parser.analizar()
print('--- AST ---')
for n in ast_nodos:
    print(n)
print()

print('--- SUGERENCIAS IA ---')
for s in (sugerencias_lexer + sugerencias_parser):
    print('-', s)
