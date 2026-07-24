/*
 * Benchmark.java
 * --------------------------------------------------------------------------
 * Driver de ejecución en Java para el benchmark de lexer/parser generado
 * por ANTLR4 a partir de grammar/YamlDocker.g4.
 *
 * Uso:
 *     java -cp .:antlr-4.13.1-complete.jar Benchmark <ruta_al_archivo.yml>
 *
 * Salida:
 *     Imprime EXCLUSIVAMENTE en stdout el tiempo transcurrido en
 *     milisegundos (double), sin texto adicional, para que
 *     scripts/run_benchmark.py pueda capturarlo directamente vía
 *     subprocess.
 *
 * Requisitos previos:
 *     - Haber generado el lexer/parser Java con:
 *         antlr4 -Dlanguage=Java -visitor -o generated/java grammar/YamlDocker.g4
 *       (ver Makefile, target `build`)
 *     - Haber compilado tanto el código generado como este driver contra
 *       antlr-4.13.1-complete.jar (runtime + herramienta en un solo jar).
 *
 * Nota sobre la medición:
 *     Se usa System.nanoTime() por ser el reloj monotónico de mayor
 *     resolución disponible en la JVM (no afectado por ajustes del reloj
 *     de pared). El resultado se convierte a milisegundos como double para
 *     mantener precisión sub-milisegundo, igual que time.perf_counter() en
 *     Python y std::chrono::high_resolution_clock en C++.
 */

import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;

import java.io.PrintStream;
import java.nio.charset.StandardCharsets;

public class Benchmark {

    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Uso: java Benchmark <archivo.yml>");
            System.exit(1);
        }

        String filepath = args[0];

        try {
            double elapsedMs = parseFile(filepath);
            // ÚNICA salida por stdout: el tiempo en milisegundos
            PrintStream out = new PrintStream(System.out, true, "UTF-8");
            out.printf("%.4f%n", elapsedMs);
        } catch (Exception e) {
            System.err.println("ERROR al parsear '" + filepath + "': " + e.getMessage());
            e.printStackTrace(System.err);
            System.exit(1);
        }
    }

    /**
     * Realiza el lexing + parsing completo del archivo dado y devuelve el
     * tiempo transcurrido en milisegundos.
     */
    private static double parseFile(String filepath) throws Exception {
        long start = System.nanoTime();

        CharStream input = CharStreams.fromFileName(filepath, StandardCharsets.UTF_8);
        YamlDockerLexer lexer = new YamlDockerLexer(input);
        lexer.removeErrorListeners(); // evita ruido de errores en stdout/stderr

        CommonTokenStream tokens = new CommonTokenStream(lexer);
        YamlDockerParser parser = new YamlDockerParser(tokens);
        parser.removeErrorListeners();

        ParseTree tree = parser.document(); // regla inicial de la gramática
        if (tree == null) {
            throw new IllegalStateException("El parser no devolvió un árbol válido");
        }

        long end = System.nanoTime();
        return (end - start) / 1_000_000.0; // nanosegundos -> milisegundos
    }
}
