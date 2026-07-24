#!/usr/bin/env python3
"""
generate_dataset.py
--------------------------------------------------------------------------
Genera n = 10 archivos docker-compose*.yml sintéticos en test_files/, con
un tamaño y complejidad creciente (desde 10 hasta 500 servicios), para que
el experimento de benchmarking (run_benchmark.py) pueda medir cómo escala
el tiempo de lexing/parsing de cada implementación (Python / Java / C++)
en función del tamaño de la entrada.

Cada archivo respeta el subconjunto de YAML aceptado por grammar/YamlDocker.g4:
  - Sección "version"
  - Sección "services", con N servicios, cada uno con:
      image, ports (2 items), environment (2 items), networks (1 item)
  - Sección "networks", con 2 redes, cada una con su "driver"

Uso:
    python3 scripts/generate_dataset.py
"""

import os

# Cantidad de archivos a generar (5 < n < 20 según el enunciado del proyecto)
N_FILES = 10

# Escalado de servicios por archivo: de 10 a 500, aproximadamente exponencial
# para que las diferencias de tiempo entre lenguajes sean visibles incluso
# en máquinas rápidas.
SERVICE_COUNTS = [10, 20, 40, 70, 110, 160, 220, 300, 390, 500]

OUTPUT_DIR = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "test_files")


def build_service_block(service_index: int) -> str:
    """Construye el bloque YAML de un único servicio docker-compose."""
    name = f"service_{service_index:04d}"
    image_tag = f"myrepo/app-{service_index % 25}:1.{service_index % 9}.{service_index % 12}"
    host_port = 8000 + (service_index % 2000)
    container_port = 80 + (service_index % 20)
    metrics_port = 9000 + (service_index % 500)
    net_name = f"net_{service_index % 4}"

    return (
        f"  {name}:\n"
        f"    image: {image_tag}\n"
        f"    ports:\n"
        f"      - {host_port}:{container_port}\n"
        f"      - {metrics_port}:{metrics_port}\n"
        f"    environment:\n"
        f"      - ENV_MODE=production\n"
        f"      - SERVICE_ID={service_index}\n"
        f"    networks:\n"
        f"      - {net_name}\n"
    )


def build_networks_block() -> str:
    """Construye el bloque "networks" con 4 redes fijas y su driver."""
    lines = ["networks:\n"]
    drivers = ["bridge", "overlay", "bridge", "host"]
    for idx, driver in enumerate(drivers):
        lines.append(f"  net_{idx}:\n")
        lines.append(f"    driver: {driver}\n")
    return "".join(lines)


def build_compose_file(n_services: int) -> str:
    """Ensambla el contenido completo de un archivo docker-compose sintético."""
    parts = ['version: "3.8"\n', "services:\n"]
    parts.extend(build_service_block(i) for i in range(n_services))
    parts.append(build_networks_block())
    return "".join(parts)


def main() -> None:
    os.makedirs(OUTPUT_DIR, exist_ok=True)

    print(f"Generando {N_FILES} archivos docker-compose sintéticos en: {OUTPUT_DIR}")
    for file_idx, n_services in enumerate(SERVICE_COUNTS[:N_FILES], start=1):
        content = build_compose_file(n_services)
        filename = f"docker-compose_{file_idx:02d}_{n_services}svc.yml"
        filepath = os.path.join(OUTPUT_DIR, filename)
        with open(filepath, "w", encoding="utf-8") as f:
            f.write(content)
        size_kb = os.path.getsize(filepath) / 1024
        print(f"  [{file_idx:02d}/{N_FILES}] {filename}  "
              f"({n_services} servicios, {size_kb:.1f} KB)")

    print("Listo.")


if __name__ == "__main__":
    main()
