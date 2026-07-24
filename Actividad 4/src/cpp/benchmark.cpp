/*
 * benchmark.cpp
 * --------------------------------------------------------------------------
 * Driver de ejecución en C++ para el benchmark de lexer/parser generado
 * por ANTLR4 a partir de grammar/YamlDocker.g4.
 *
 * Uso:
 *     ./benchmark <ruta_al_archivo.yml>
 *
 * Salida:
 *     Imprime EXCLUSIVAMENTE en stdout el tiempo transcurrido en
 *     milisegundos (double), sin texto adicional, para que
 *     scripts/run_benchmark.py pueda capturarlo directamente vía
 *     subprocess.
 *
 * Requisitos previos:
 *     - Haber generado el lexer/parser C++ con:
 *         antlr4 -Dlanguage=Cpp -visitor -o generated/cpp grammar/YamlDocker.g4
 *       (ver Makefile, target `build`)
 *     - Tener instalado antlr4-cpp-runtime (headers + libantlr4-runtime.so/.a)
 *     - Compilar este archivo junto con el código generado, enlazando contra
 *       antlr4-runtime (ver Makefile, target `build`).
 *
 * Nota sobre la medición:
 *     Se usa std::chrono::high_resolution_clock, el reloj de mayor
 *     resolución disponible en <chrono>, equivalente en propósito a
 *     time.perf_counter() (Python) y System.nanoTime() (Java).
 */

#include <iostream>
#include <chrono>
#include <string>
#include <cstdio>

#include "antlr4-runtime.h"
#include "YamlDockerLexer.h"
#include "YamlDockerParser.h"

using namespace antlr4;

// Listener de errores "silencioso": evita que ANTLR imprima diagnósticos en
// stderr/stdout durante la medición, igual que removeErrorListeners() en
// las versiones Python y Java del driver.
class SilentErrorListener : public BaseErrorListener {
public:
    void syntaxError(Recognizer * /*recognizer*/, Token * /*offendingSymbol*/,
                      size_t /*line*/, size_t /*charPositionInLine*/,
                      const std::string & /*msg*/, std::exception_ptr /*e*/) override {
        // Intencionalmente vacío: se descartan los errores de sintaxis
        // para que no contaminen stdout durante la medición de tiempos.
    }
};

static double parseFile(const std::string &filepath) {
    auto start = std::chrono::high_resolution_clock::now();

    std::ifstream stream;
    stream.open(filepath);
    if (!stream.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo: " + filepath);
    }

    ANTLRInputStream input(stream);
    YamlDockerLexer lexer(&input);

    SilentErrorListener silentListener;
    lexer.removeErrorListeners();
    lexer.addErrorListener(&silentListener);

    CommonTokenStream tokens(&lexer);
    YamlDockerParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(&silentListener);

    tree::ParseTree *tree = parser.document(); // regla inicial de la gramática
    if (tree == nullptr) {
        throw std::runtime_error("El parser no devolvio un arbol valido");
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    return elapsed.count();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <archivo.yml>" << std::endl;
        return 1;
    }

    std::string filepath = argv[1];

    try {
        double elapsedMs = parseFile(filepath);
        // UNICA salida por stdout: el tiempo en milisegundos
        std::printf("%.4f\n", elapsedMs);
    } catch (const std::exception &e) {
        std::cerr << "ERROR al parsear '" << filepath << "': " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
