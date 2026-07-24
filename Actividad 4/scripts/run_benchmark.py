#!/usr/bin/env python3
"""
run_benchmark.py
--------------------------------------------------------------------------
Script maestro del experimento. Para cada uno de los n=10 archivos
docker-compose*.yml en test_files/, ejecuta los 3 drivers de parsing
(Python, Java, C++) mediante subprocess, captura el tiempo reportado por
cada uno (impreso en stdout, en milisegundos) y:

  1. Repite cada ejecución REPETITIONS veces por archivo/lenguaje, para
     amortiguar ruido del sistema operativo y reportar tiempo medio.
  2. Guarda todos los resultados crudos en results.csv.
  3. Genera una gráfica benchmark_results.png (Eje X: tamaño del archivo en
     número de servicios, Eje Y: tiempo medio en ms) con una curva por
     lenguaje.

Uso:
    python3 scripts/run_benchmark.py

Precondiciones:
    - test_files/ debe existir y contener los YAML (ver generate_dataset.py)
    - El código ANTLR debe estar generado y compilado para los 3 lenguajes
      (ver Makefile, target `build`)
"""

import csv
import os
import re
import subprocess
import sys

import matplotlib
matplotlib.use("Agg")  # backend sin GUI, apto para entornos headless
import matplotlib.pyplot as plt

PROJECT_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TEST_FILES_DIR = os.path.join(PROJECT_ROOT, "test_files")
RESULTS_CSV = os.path.join(PROJECT_ROOT, "results.csv")
RESULTS_PNG = os.path.join(PROJECT_ROOT, "benchmark_results.png")

REPETITIONS = 5  # corridas por archivo/lenguaje, se reporta el promedio

# Comandos de cada driver. {file} se sustituye por la ruta del YAML.
# Se asume que 'make build' ya generó/compiló los artefactos necesarios.
LANGUAGES = {
    "Python": {
        "cmd": [sys.executable, os.path.join(PROJECT_ROOT, "src", "python", "parse_test.py"), "{file}"],
        "color": "#3776AB",
    },
    "Java": {
        "cmd": ["java", "-cp",
                os.pathsep.join([
                    os.path.join(PROJECT_ROOT, "build", "java"),
                    os.path.join(PROJECT_ROOT, "lib", "antlr-4.13.1-complete.jar"),
                ]),
                "Benchmark", "{file}"],
        "color": "#E76F00",
    },
    "C++": {
        "cmd": [os.path.join(PROJECT_ROOT, "build", "cpp", "benchmark"), "{file}"],
        "color": "#00599C",
    },
}


def extract_service_count(filename: str) -> int:
    """Extrae el número de servicios codificado en el nombre del archivo
    generado por generate_dataset.py (ej. docker-compose_05_110svc.yml -> 110)."""
    match = re.search(r"_(\d+)svc", filename)
    return int(match.group(1)) if match else 0


def run_single(cmd: list, filepath: str) -> float:
    """Ejecuta un driver sobre un archivo y devuelve el tiempo en ms que
    el propio driver imprimió por stdout."""
    full_cmd = [part.format(file=filepath) for part in cmd]
    result = subprocess.run(full_cmd, capture_output=True, text=True, timeout=120)
    if result.returncode != 0:
        raise RuntimeError(
            f"El comando {' '.join(full_cmd)} falló (código {result.returncode}).\n"
            f"stderr: {result.stderr}"
        )
    return float(result.stdout.strip())


def main() -> None:
    if not os.path.isdir(TEST_FILES_DIR):
        sys.exit(f"ERROR: no existe {TEST_FILES_DIR}. Ejecuta primero generate_dataset.py")

    test_files = sorted(
        f for f in os.listdir(TEST_FILES_DIR) if f.endswith(".yml")
    )
    if not test_files:
        sys.exit(f"ERROR: no se encontraron archivos .yml en {TEST_FILES_DIR}")

    # rows: cada fila = (archivo, n_servicios, lenguaje, repeticion, tiempo_ms)
    rows = []
    # avg_by_lang[lang] = lista de (n_servicios, tiempo_medio_ms) ordenada por archivo
    avg_by_lang = {lang: [] for lang in LANGUAGES}

    print(f"Ejecutando benchmark sobre {len(test_files)} archivos x "
          f"{len(LANGUAGES)} lenguajes x {REPETITIONS} repeticiones...\n")

    for filename in test_files:
        filepath = os.path.join(TEST_FILES_DIR, filename)
        n_services = extract_service_count(filename)
        print(f"Archivo: {filename}  ({n_services} servicios)")

        for lang, spec in LANGUAGES.items():
            times_ms = []
            try:
                for rep in range(1, REPETITIONS + 1):
                    t_ms = run_single(spec["cmd"], filepath)
                    times_ms.append(t_ms)
                    rows.append([filename, n_services, lang, rep, f"{t_ms:.4f}"])
                avg_ms = sum(times_ms) / len(times_ms)
                avg_by_lang[lang].append((n_services, avg_ms))
                print(f"  {lang:8s}: media={avg_ms:8.3f} ms  "
                      f"(min={min(times_ms):.3f}, max={max(times_ms):.3f})")
            except (RuntimeError, FileNotFoundError) as exc:
                print(f"  {lang:8s}: OMITIDO -> {exc}")
        print()

    # ---- Guardar CSV con resultados crudos -------------------------------
    with open(RESULTS_CSV, "w", newline="", encoding="utf-8") as f:
        writer = csv.writer(f)
        writer.writerow(["file", "n_services", "language", "repetition", "time_ms"])
        writer.writerows(rows)
    print(f"Resultados crudos guardados en: {RESULTS_CSV}")

    # ---- Graficar tiempo medio vs tamaño, una curva por lenguaje ----------
    plt.figure(figsize=(10, 6))
    for lang, points in avg_by_lang.items():
        if not points:
            continue
        points.sort(key=lambda p: p[0])
        x = [p[0] for p in points]
        y = [p[1] for p in points]
        plt.plot(x, y, marker="o", label=lang, color=LANGUAGES[lang]["color"], linewidth=2)

    plt.title("Benchmark de Lexer/Parser ANTLR4 — docker-compose.yml\n"
              "Python vs Java vs C++")
    plt.xlabel("Tamaño del archivo (número de servicios)")
    plt.ylabel(f"Tiempo medio de parsing (ms, {REPETITIONS} repeticiones)")
    plt.legend()
    plt.grid(True, linestyle="--", alpha=0.5)
    plt.tight_layout()
    plt.savefig(RESULTS_PNG, dpi=150)
    print(f"Gráfica guardada en: {RESULTS_PNG}")


if __name__ == "__main__":
    main()
