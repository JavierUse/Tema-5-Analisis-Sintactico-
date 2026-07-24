#!/usr/bin/env python3
"""
parse_test.py
--------------------------------------------------------------------------
Driver de ejecución en Python para el benchmark de lexer/parser generado
por ANTLR4 a partir de grammar/YamlDocker.g4.

Uso:
    python3 parse_test.py <ruta_al_archivo.yml>

Salida:
    Imprime EXCLUSIVAMENTE en stdout el tiempo transcurrido en milisegundos
    (float), sin texto adicional, para que run_benchmark.py pueda capturarlo
    directamente vía subprocess.

Requisitos previos:
    - Haber generado el lexer/parser Python con:
        antlr4 -Dlanguage=Python3 -visitor -o generated/python grammar/YamlDocker.g4
      (ver Makefile, target `build`)
    - Tener instalado antlr4-python3-runtime (ver requirements.txt)
    - El código generado (YamlDockerLexer.py, YamlDockerParser.py) debe estar
      accesible en el PYTHONPATH; este script asume que se colocó en
      generated/python/ en la raíz del proyecto y ajusta sys.path acorde.
"""

import sys
import os
import time

# Permite ejecutar el script desde cualquier directorio y localizar el
# código generado por ANTLR en <raiz_proyecto>/generated/python
_THIS_DIR = os.path.dirname(os.path.abspath(__file__))
_PROJECT_ROOT = os.path.abspath(os.path.join(_THIS_DIR, "..", ".."))
_GENERATED_DIR = os.path.join(_PROJECT_ROOT, "generated", "python")
sys.path.insert(0, _GENERATED_DIR)

from antlr4 import FileStream, CommonTokenStream  # noqa: E402

try:
    from YamlDockerLexer import YamlDockerLexer  # noqa: E402
    from YamlDockerParser import YamlDockerParser  # noqa: E402
except ImportError as exc:
    sys.stderr.write(
        "ERROR: no se encontró el código generado por ANTLR en "
        f"'{_GENERATED_DIR}'.\n"
        "Ejecuta primero 'make build' (o el comando antlr4 correspondiente) "
        "para generar YamlDockerLexer.py / YamlDockerParser.py.\n"
        f"Detalle: {exc}\n"
    )
    sys.exit(1)


def parse_file(filepath: str) -> float:
    """Realiza el lexing + parsing completo del archivo dado y devuelve el
    tiempo transcurrido en milisegundos, medido con precisión de reloj de
    alta resolución (time.perf_counter)."""
    start = time.perf_counter()

    input_stream = FileStream(filepath, encoding="utf-8")
    lexer = YamlDockerLexer(input_stream)
    token_stream = CommonTokenStream(lexer)
    parser = YamlDockerParser(token_stream)
    parser.removeErrorListeners()  # evita ruido de errores en stdout/stderr

    tree = parser.document()  # regla inicial de la gramática
    _ = tree  # el árbol no se usa más allá de forzar el parsing completo

    end = time.perf_counter()
    elapsed_ms = (end - start) * 1000.0
    return elapsed_ms


def main() -> None:
    if len(sys.argv) != 2:
        sys.stderr.write("Uso: python3 parse_test.py <archivo.yml>\n")
        sys.exit(1)

    filepath = sys.argv[1]
    if not os.path.isfile(filepath):
        sys.stderr.write(f"ERROR: el archivo '{filepath}' no existe.\n")
        sys.exit(1)

    elapsed_ms = parse_file(filepath)
    # ÚNICA salida por stdout: el tiempo en milisegundos
    print(f"{elapsed_ms:.4f}")


if __name__ == "__main__":
    main()
