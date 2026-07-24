# docker-parser-benchmark

Proyecto de benchmarking de lexers/parsers generados con **ANTLR4** para el
análisis de archivos `docker-compose.yml`, implementado en **3 lenguajes
distintos** (Python, Java, C++) a partir de una **única gramática compartida**
(`grammar/YamlDocker.g4`), tal como exige el enunciado: usar el mismo
metacompilador y comparar únicamente el efecto de la implementación/runtime
de cada lenguaje sobre el tiempo de ejecución.

## 1. Enunciado del proyecto

> "Considerando el archivo docker compose utilizado por docker para describir
> una de las interfaces de red del sistema, crear lexer y parser. Realizar un
> experimento de carga de ejecución de al menos 3 parser mediante su
> metacompilador con código en diferentes lenguajes ejemplo: C, rust, java o
> python, etc. [...] Para el experimento se requieren n (5 < n < 20) archivos
> docker para ser analizados, ejecutar por cada lexer-parser, medir tiempo de
> ejecución, graficar."

## 2. Estructura del proyecto

```
docker-parser-benchmark/
├── grammar/
│   └── YamlDocker.g4            # Gramática ANTLR4 (fuente única, 3 targets)
├── scripts/
│   ├── generate_dataset.py      # Genera n=10 archivos YAML de prueba
│   └── run_benchmark.py         # Ejecuta, mide y grafica el experimento
├── src/
│   ├── python/parse_test.py     # Driver Python (time.perf_counter)
│   ├── java/Benchmark.java      # Driver Java (System.nanoTime)
│   └── cpp/benchmark.cpp        # Driver C++ (std::chrono::high_resolution_clock)
├── test_files/                  # 10 archivos docker-compose*.yml (generados)
├── generated/                   # Código fuente emitido por ANTLR (generado)
├── build/                       # Binarios/clases compiladas (generado)
├── lib/antlr-4.13.1-complete.jar  # Metacompilador ANTLR (descarga manual)
├── requirements.txt
├── Makefile
└── README.md
```

## 3. La gramática: un subset de YAML para docker-compose

`grammar/YamlDocker.g4` reconoce las secciones `version`, `services`
(con `image`, `ports`, `environment`, `networks` por servicio) y `networks`
(con `driver` por red).

**Simplificación de contexto sobre indentaciones** (documentada también como
comentario dentro del propio `.g4`): YAML real es sensible a la indentación
(off-side rule), lo que en un lexer LL clásico como el de ANTLR4 exigiría un
mecanismo de pila INDENT/DEDENT similar al de Python, implementado con un
`TokenFactory` a medida. Para mantener el foco del experimento en la
**medición de tiempos** y no en la ingeniería de un lexer de indentación
completo, esta gramática:

- Descarta espacios/tabs de inicio de línea (`WS: [ \t]+ -> skip`).
- Infiere la jerarquía (qué propiedades pertenecen a qué servicio, qué items
  a qué lista) mediante el **orden secuencial de palabras clave** y
  separadores explícitos (`:`, `-`, `NEWLINE`), no mediante la profundidad de
  sangría real.
- Como consecuencia, el subset aceptado es más rígido que YAML general, pero
  suficiente para los archivos `docker-compose` sintéticos generados por
  `generate_dataset.py`, que siempre respetan el mismo orden y una sangría
  canónica de 2 espacios (sangría que el parser nunca valida).

## 4. Dataset del experimento

`scripts/generate_dataset.py` genera **n = 10** archivos (dentro del rango
`5 < n < 20` exigido), con tamaño creciente para poder observar cómo escala
cada implementación:

| # | Archivo                          | Servicios | Tamaño aprox. |
|---|-----------------------------------|-----------|----------------|
| 1 | docker-compose_01_10svc.yml       | 10        | ~2 KB          |
| 2 | docker-compose_02_20svc.yml       | 20        | ~4 KB          |
| 3 | docker-compose_03_40svc.yml       | 40        | ~7 KB          |
| 4 | docker-compose_04_70svc.yml       | 70        | ~13 KB         |
| 5 | docker-compose_05_110svc.yml      | 110       | ~20 KB         |
| 6 | docker-compose_06_160svc.yml      | 160       | ~29 KB         |
| 7 | docker-compose_07_220svc.yml      | 220       | ~40 KB         |
| 8 | docker-compose_08_300svc.yml      | 300       | ~55 KB         |
| 9 | docker-compose_09_390svc.yml      | 390       | ~72 KB         |
| 10| docker-compose_10_500svc.yml      | 500       | ~92 KB         |

Cada servicio incluye `image`, 2 `ports`, 2 `environment` y 1 referencia a
`networks`, más un bloque `networks` fijo con 4 redes al final del archivo.

## 5. Instalación y ejecución

### 5.1. Requisitos de entorno

- Java JDK ≥ 11 (para correr el `.jar` de ANTLR y compilar/ejecutar el driver Java)
- Python 3.9+ y `pip`
- `g++` con soporte C++17
- `antlr4-cpp-runtime` (headers + librería). En Debian/Ubuntu:
  ```bash
  sudo apt install antlr4 libantlr4-runtime-dev
  ```
- El metacompilador ANTLR4:
  ```bash
  mkdir -p lib
  curl -o lib/antlr-4.13.1-complete.jar \
       https://www.antlr.org/download/antlr-4.13.1-complete.jar
  ```

### 5.2. Comandos

```bash
make build           # Genera + compila lexer/parser para Python, Java y C++
make generate-data    # Crea los 10 archivos docker-compose de prueba
make run              # Ejecuta el benchmark completo y genera la gráfica
# o, todo de una vez:
make all
```

Al finalizar `make run` se generan:
- `results.csv` — tiempos crudos de cada repetición (5 por archivo/lenguaje)
- `benchmark_results.png` — gráfica tiempo (ms) vs tamaño (nº de servicios),
  una curva por lenguaje

`make clean` elimina todos los artefactos generados/compilados.

## 6. Metodología de medición

Cada driver (`parse_test.py`, `Benchmark.java`, `benchmark.cpp`) recibe la
ruta de un archivo por línea de comandos, mide **únicamente** el tiempo de
lexing + parsing (construcción del `ParseTree` vía la regla inicial
`document`) usando el reloj de mayor resolución disponible en su ecosistema
(`time.perf_counter`, `System.nanoTime`, `std::chrono::high_resolution_clock`),
e imprime solo ese valor en milisegundos por `stdout`. `run_benchmark.py`
orquesta 5 repeticiones por combinación archivo × lenguaje y reporta la
media, para amortiguar el ruido propio del sistema operativo (scheduling,
caché de disco, recolección de basura en el caso de Java).

## 7. Justificación teórica de los resultados esperados

Aunque los tres drivers ejecutan **la misma gramática** generada por el
**mismo metacompilador**, se espera que los tiempos difieran de forma
sistemática entre lenguajes, por razones inherentes a cada runtime y no a la
gramática en sí:

**C++ — el más rápido y el más estable.** El código generado por ANTLR para
C++ se compila directamente a instrucciones nativas de la máquina, sin capa
de interpretación ni máquina virtual intermedia. El manejo de memoria es
explícito y predecible (sin pausas de recolección de basura), y el
optimizador de `g++` (`-O2`) puede realizar inlining agresivo sobre las
rutinas del runtime `antlr4-cpp-runtime`. Se espera, por tanto, el tiempo de
ejecución más bajo y la menor varianza entre repeticiones, con una curva
prácticamente lineal respecto al tamaño del archivo.

**Java — lento al inicio ("warm-up" de la JVM), rápido después (JIT).** La
primera ejecución de código Java en una JVM se interpreta en bytecode antes
de que el compilador Just-In-Time (JIT, por ejemplo C2 en HotSpot) detecte
las rutinas "calientes" del lexer/parser generado y las compile a código
nativo. Como cada invocación de `Benchmark` en este experimento es un
**proceso nuevo** (vía `subprocess`), la JVM parte de cero en cada
repetición: se espera, por tanto, que Java muestre tiempos más altos y más
variables que C++ para archivos pequeños (donde el costo fijo de arranque de
la JVM y el "cold start" del JIT dominan sobre el trabajo real de parsing),
pero que su curva se aplane relativamente bien para archivos grandes, una
vez que el propio trabajo de parsing (con partes ya JIT-compiladas dentro de
la misma ejecución) empieza a dominar sobre el costo fijo de arranque.

**Python — el más lento por el overhead del intérprete.** El runtime
`antlr4-python3-runtime` ejecuta el lexer/parser generado sobre el
intérprete CPython estándar: cada token consumido y cada regla de la
gramática invocada implican operaciones de bytecode interpretado, con
overhead adicional por el manejo dinámico de tipos, el conteo de referencias
para recolección de basura y la ausencia de compilación JIT en CPython
"vanilla". Se espera, por tanto, que Python muestre los tiempos más altos de
los tres lenguajes en todo el rango de tamaños, con una curva que crece de
forma aproximadamente lineal (igual que C++ y Java, porque la gramática y el
algoritmo de parsing —ALL(*)— son los mismos), pero con una pendiente mucho
más pronunciada.

**Resumen esperado (de más rápido a más lento, para archivos grandes):**
`C++ < Java < Python`, con la salvedad de que Java puede resultar más lento
que C++ o incluso comparable a Python en los archivos más pequeños del
dataset, debido al costo fijo de arranque de la JVM por proceso — un efecto
que se vuelve proporcionalmente menos relevante a medida que crece `n`
(número de servicios), que es precisamente la razón por la que el dataset
generado escala de 10 a 500 servicios.

## 8. Limitaciones conocidas

- La gramática no valida indentación real de YAML (ver nota de diseño en
  `grammar/YamlDocker.g4` y sección 3 de este README); solo procesa el
  subconjunto rígido producido por `generate_dataset.py`.
- Medir Java lanzando un proceso nuevo por archivo penaliza artificialmente
  el "warm-up" de la JVM en cada muestra; una JVM persistente que parseara
  los 10 archivos en el mismo proceso mostraría tiempos de Java más
  favorables una vez estabilizado el JIT. Se documenta este efecto en la
  sección 7 en lugar de ocultarlo, porque es en sí mismo un resultado
  académicamente relevante del experimento.
- Los tiempos absolutos dependen fuertemente del hardware, la carga del
  sistema al momento de ejecutar y la versión de cada runtime; lo
  comparativamente estable entre ejecuciones es el **orden relativo** y la
  **forma de la curva** de cada lenguaje, no los valores absolutos en ms.
