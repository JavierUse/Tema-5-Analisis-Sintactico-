# ============================================================================
# Makefile — docker-parser-benchmark
# ----------------------------------------------------------------------------
# Automatiza: generación de código ANTLR (Python/Java/C++), compilación de
# los drivers Java y C++, generación del dataset de prueba y ejecución
# completa del benchmark con graficado.
#
# Requisitos de entorno (instalar antes de usar este Makefile):
#   - Java JRE/JDK >= 11        (para correr antlr4.jar y para el driver Java)
#   - Python3 + pip              (para antlr4-python3-runtime y matplotlib)
#   - g++ con soporte C++17      (para el driver C++)
#   - antlr4-cpp-runtime         (headers + libantlr4-runtime, vía apt/vcpkg/brew)
#   - lib/antlr-4.13.1-complete.jar
#       Descargar de: https://www.antlr.org/download/antlr-4.13.1-complete.jar
#       y colocarlo en la carpeta lib/ (crear la carpeta si no existe).
# ============================================================================

PROJECT_ROOT   := $(shell pwd)
ANTLR_JAR      := $(PROJECT_ROOT)/lib/antlr-4.13.1-complete.jar
ANTLR_CMD      := java -jar $(ANTLR_JAR)
GRAMMAR        := grammar/YamlDocker.g4

GEN_PY_DIR     := generated/python
GEN_JAVA_DIR   := generated/java
GEN_CPP_DIR    := generated/cpp

BUILD_JAVA_DIR := build/java
BUILD_CPP_DIR  := build/cpp

CXX            ?= g++
CXXFLAGS       := -std=c++17 -O2 -I $(GEN_CPP_DIR) -I /usr/local/include/antlr4-runtime -I /usr/include/antlr4-runtime
LDFLAGS        := -lantlr4-runtime

.PHONY: all build build-python build-java build-cpp generate-data run clean check-antlr-jar

all: build generate-data run

# ----------------------------------------------------------------------------
# build: genera código ANTLR para los 3 lenguajes y compila Java + C++
# ----------------------------------------------------------------------------
build: check-antlr-jar build-python build-java build-cpp
	@echo ">> Build completo (Python listo para ejecutar; Java y C++ compilados)."

check-antlr-jar:
	@if [ ! -f "$(ANTLR_JAR)" ]; then \
		echo "ERROR: no se encontró $(ANTLR_JAR)"; \
		echo "Descárgalo de https://www.antlr.org/download/antlr-4.13.1-complete.jar y colócalo en lib/"; \
		exit 1; \
	fi

build-python: check-antlr-jar
	@echo ">> Generando lexer/parser Python3..."
	mkdir -p $(GEN_PY_DIR)
	cd grammar && $(ANTLR_CMD) -Dlanguage=Python3 -visitor -o $(PROJECT_ROOT)/$(GEN_PY_DIR) YamlDocker.g4
	pip install -r requirements.txt --break-system-packages || pip install -r requirements.txt

build-java: check-antlr-jar
	@echo ">> Generando lexer/parser Java..."
	mkdir -p $(GEN_JAVA_DIR) $(BUILD_JAVA_DIR)
	cd grammar && $(ANTLR_CMD) -Dlanguage=Java -visitor -o $(PROJECT_ROOT)/$(GEN_JAVA_DIR) YamlDocker.g4
	@echo ">> Compilando driver Java..."
	javac -cp $(ANTLR_JAR) -d $(BUILD_JAVA_DIR) \
		$(GEN_JAVA_DIR)/*.java src/java/Benchmark.java

build-cpp: check-antlr-jar
	@echo ">> Generando lexer/parser C++..."
	mkdir -p $(GEN_CPP_DIR) $(BUILD_CPP_DIR)
	cd grammar && $(ANTLR_CMD) -Dlanguage=Cpp -visitor -o $(PROJECT_ROOT)/$(GEN_CPP_DIR) YamlDocker.g4
	@echo ">> Compilando driver C++..."
	$(CXX) $(CXXFLAGS) \
		$(GEN_CPP_DIR)/*.cpp src/cpp/benchmark.cpp \
		-o $(BUILD_CPP_DIR)/benchmark $(LDFLAGS)

# ----------------------------------------------------------------------------
# generate-data: crea los n=10 archivos docker-compose de prueba
# ----------------------------------------------------------------------------
generate-data:
	python3 scripts/generate_dataset.py

# ----------------------------------------------------------------------------
# run: ejecuta el benchmark completo (Python/Java/C++ x 10 archivos) y grafica
# ----------------------------------------------------------------------------
run:
	python3 scripts/run_benchmark.py

# ----------------------------------------------------------------------------
# clean: elimina todos los artefactos generados/compilados
# ----------------------------------------------------------------------------
clean:
	rm -rf $(GEN_PY_DIR) $(GEN_JAVA_DIR) $(GEN_CPP_DIR)
	rm -rf $(BUILD_JAVA_DIR) $(BUILD_CPP_DIR)
	rm -rf test_files
	rm -f results.csv benchmark_results.png
	rm -f src/python/*.pyc
	find . -name "__pycache__" -type d -exec rm -rf {} + 2>/dev/null || true
	@echo ">> Limpieza completa."
