# INFORME DE INVESTIGACION - Actividad 2 Y 3

## Tema 5: Analisis Sintactico
### Lenguaje y Compiladores - Trimestre 2026-I
### Universidad Nacional Experimental de Guayana (UNEG)
### Seccion 01 y 02 - Ing. Felix Marquez

---

## Actividad 2: COMPARACION ENTRE ANALISIS LL Y LR

### 2.1 Definiciones Fundamentales

#### Parser LL (Left-to-right, Leftmost derivation)
Los parsers LL realizan un analisis **descendente** (top-down), construyendo el arbol de derivacion desde la raiz (simbolo inicial) hacia las hojas (tokens). La denominacion indica:
- **L**eft-to-right: Lee la entrada de izquierda a derecha
- **L**eftmost derivation: Realiza la derivacion por la izquierda

El parser LL mas comun es el **recursivo descendente**, donde cada no-terminal de la gramatica se implementa como una funcion que reconoce las producciones correspondientes. La variante **LL(1)** utiliza un solo token de lookahead para decidir que produccion aplicar.

#### Parser LR (Left-to-right, Rightmost derivation)
Los parsers LR realizan un analisis **ascendente** (bottom-up), construyendo el arbol desde las hojas hacia la raiz mediante **reducciones**. La denominacion indica:
- **L**eft-to-right: Lee la entrada de izquierda a derecha
- **R**ightmost derivation: Construye la derivacion por la derecha (en sentido inverso)

Los parsers LR son **tabla-driven**: utilizan una pila de estados y una tabla de analisis (ACTION/GOTO) para decidir entre operaciones de **shift** (desplazar token a la pila) o **reduce** (reducir produccion).

### 2.2 Tabla Comparativa Detallada

| Criterio | LL (Recursivo Descendente) | LR (Tabla-Driven) |
|:---|:---|:---|
| **Estrategia** | Descendente (Top-Down) | Ascendente (Bottom-Up) |
| **Derivacion** | Por la izquierda | Por la derecha (inversa) |
| **Construccion del arbol** | De raiz a hojas | De hojas a raiz |
| **Complejidad de implementacion** | Baja (funciones recursivas) | Alta (tablas grandes) |
| **Complejidad algoritmica** | O(n) | O(n) - O(n^4) teorico para ALL(*) |
| **Memoria requerida** | Pila de llamadas (O(depth)) | Pila de estados + tabla (O(n)) |
| **Gramaticas soportadas** | No ambiguas, sin recursion izquierda | Gramaticas mas generales, incluye recursion izquierda |
| **Deteccion de errores** | Inmediata (al primer token inesperado) | Retardada (hasta que no puede reducir) |
| **Mensajes de error** | Faciles de personalizar | Mas cripticos (dependen de la tabla) |
| **Mantenimiento** | Facil de modificar manualmente | Requiere regenerar tablas |
| **Rendimiento** | Rapido (llamadas a funciones) | Muy rapido (acceso a tabla) |
| **Herramientas** | ANTLR (ALL(*)), JavaCC, Coco/R | Bison/Yacc (LALR), Menhir (LR(1)), Happy |

### 2.3 Evidencia de Uso Actual en la Industria (2025-2026)

#### Uso de LL Parsers
Segun investigaciones recientes, los parsers LL dominan en el desarrollo moderno de lenguajes y herramientas de productividad:

1. **ANTLR 4** (Adaptive LL(*)): Es el parser generator mas utilizado en la actualidad. Se emplea en:
   - **Hibernate** (ORM de Java)
   - **Twitter Search** (query parsing)
   - **Hadoop** (Hive, Pig)
   - **Oracle SQL Developer** IDE
   - **Presto/Trino** (motor SQL distribuido)
   - **Spark SQL** (Apache Spark)

2. **Rust**: El compilador de Rust utiliza un parser recursivo descendente hand-written, aprovechando las ventajas de LL para mensajes de error excepcionales.

3. **Go**: El compilador oficial (`gc`) usa un parser recursivo descendente LL(1) manual.

4. **TypeScript**: El parser de Microsoft es un recursivo descendente manual que prioriza la recuperacion de errores y la resiliencia.

5. **Python**: A partir de Python 3.9, el parser oficial migro de LL(1) a PEG (Parsing Expression Grammar), que es una extension de LL con lookahead ilimitado.

#### Uso de LR Parsers
Los parsers LR mantienen su relevancia en sistemas tradicionales y academicos:

1. **GCC**: El compilador GNU C utiliza un parser LALR(1) generado con Bison.

2. **PostgreSQL**: El parser SQL es generado con Bison (LALR).

3. **MySQL/MariaDB**: Utilizan Bison para el parsing SQL.

4. **PHP**: El parser oficial se genera con Bison.

5. **Ruby**: El parser original (YARV) era generado con Bison, aunque versiones recientes han migrado a parsers hand-written.

6. **Universidades**: Segun un estudio empirico de 2021 sobre las top 16 universidades del mundo (MIT, Stanford, Berkeley, ETH Zurich, etc.), 13 de 16 utilizan variantes de Lex/Yacc/Bison (LR) en sus cursos de compiladores, mientras que solo MIT usa ANTLR (LL) como herramienta principal.

#### Tendencias Actuales
- **Migracion a LL**: Muchos lenguajes modernos (Rust, Go, TypeScript, Swift) prefieren parsers recursivos descendentes hand-written por la calidad de errores y facilidad de depuracion.
- **Herramientas hibridas**: ANTLR 4 con su algoritmo ALL(*) ha cerrado la brecha de poder expresivo, manejando gramaticas que tradicionalmente requerian LR.
- **Parser Combinators**: En lenguajes funcionales (Haskell, Scala, Rust), los parser combinators (variantes de LL) ganan popularidad por su composabilidad.

### 2.4 Implementaciones para el Mismo Lenguaje

Se han implementado dos parsers completos para una **Calculadora de Expresiones Aritmeticas** que soporta:
- Numeros enteros
- Operadores: `+`, `-`, `*`, `/`
- Parentesis para agrupacion
- Precedencia: `*` y `/` tienen mayor precedencia que `+` y `-`
- Asociatividad: Izquierda

#### Implementacion LL(1): Parser Recursivo Descendente

**Gramatica LL(1) utilizada** (sin recursion izquierda, factorizada):
```
E  -> T E1
E1 -> + T E1 | - T E1 | epsilon
T  -> F T1
T1 -> * F T1 | / F T1 | epsilon
F  -> ( E ) | NUM
```

**Caracteristicas de la implementacion**:
- Lexer basado en AFD (Automata Finito Determinista)
- Parser con funciones recursivas por cada no-terminal
- Construccion de AST (Arbol de Sintaxis Abstracta)
- Evaluacion del AST mediante recorrido recursivo
- Recuperacion basica de errores (avance al siguiente token)

**Archivo**: `parser_ll.py`

#### Implementacion LR(1): Parser Tabla-Driven

**Gramatica LR(1) utilizada** (con recursion izquierda permitida):
```
0. S1 -> S
1. S  -> E
2. E  -> E + T
3. E  -> E - T
4. E  -> T
5. T  -> T * F
6. T  -> T / F
7. T  -> F
8. F  -> ( E )
9. F  -> NUM
```

**Caracteristicas de la implementacion**:
- Lexer identico al LL para comparacion justa
- Tabla ACTION/GOTO construida manualmente (16 estados)
- Algoritmo de analisis bottom-up con pila de estados
- Construccion de AST durante las reducciones
- Evaluacion bottom-up (los resultados se propagan desde las hojas)
- Manejo de errores con deteccion de tokens inesperados

**Archivo**: `parser_lr.py`

#### Resultados de Prueba Comparativa

| Expresion de Entrada | Resultado LL(1) | Resultado LR(1) | Pasos LR |
|:---|:---|:---|:---|
| `3 + 5` | 8 | 8 | 10 |
| `10 - 2 * 3` | 4 | 4 | 14 |
| `(4 + 6) / 2` | 5.0 | 5.0 | 19 |
| `8 / 2 + 3 * 2` | 10.0 | 10.0 | 18 |
| `42` | 42 | 42 | 5 |
| `(1 + 2) * (3 + 4)` | 21 | 21 | 29 |

**Analisis de resultados**:
- Ambos parsers producen **resultados identicos**, validando la equivalencia semantica
- El parser LR requiere mas pasos de analisis (operaciones shift/reduce) debido a la naturaleza bottom-up
- El parser LL construye el arbol de forma mas directa (top-down), mientras que LR requiere reducciones intermedias
- El AST de LR refleja la estructura bottom-up con nodos intermedios de reduccion visibles

---

## Actividad 3: GENERADORES DE ANALIZADORES SINTACTICOS Y GESTION DE ERRORES

### 3.1 Resumen de Generadores de Analizadores Sintacticos

#### 3.1.1 ANTLR (Another Tool for Language Recognition)

**Descripcion**: ANTLR es el parser generator mas popular y moderno, desarrollado por Terence Parr. La version 4 utiliza el algoritmo **ALL(*)** (Adaptive LL(*)), que combina la simplicidad de LL con el poder expresivo cercano a LR.

**Caracteristicas**:
- Soporta multiples lenguajes objetivo: Java, C#, C++, Python, JavaScript, Swift, Go, PHP
- Gramatica en formato EBNF (mas legible que BNF)
- Generacion automatica de arboles de parseo (parse trees)
- Separacion entre gramatica y codigo de acciones semanticas (patrones Visitor/Listener)
- IDE propio (ANTLRWorks) para visualizacion y debugging de gramaticas
- Soporte completo para Unicode
- Plugin para IntelliJ, NetBeans, Eclipse, Visual Studio

**Uso en la industria**: Twitter, Hadoop, Hive, Presto, Oracle SQL Developer, Hibernate.

**Gestion de errores**:
- **Recuperacion por modo panico (panic mode)**: ANTLR descarta tokens hasta encontrar uno de sincronizacion
- **Recuperacion por reglas de seguimiento**: Utiliza tokens FOLLOW para decidir cuando detener la recuperacion
- **Mensajes de error contextuales**: Reporta la regla gramatical donde ocurrio el error
- **Recuperacion en expresiones**: Maneja especialmente bien errores en expresiones anidadas

#### 3.1.2 Bison (GNU Parser Generator)

**Descripcion**: Bison es la implementacion GNU de Yacc (Yet Another Compiler Compiler). Genera parsers LALR(1), LR(1), IELR(1) y GLR.

**Caracteristicas**:
- Lenguajes de salida: C, C++, D, Java, XML
- Gramatica en formato BNF/Yacc
- Requiere lexer externo (generalmente Flex)
- Licencia GPL con excepcion para parsers generados
- Soporta recursion izquierda (directa e indirecta)
- GLR (Generalized LR) para gramaticas ambiguas

**Uso en la industria**: GCC, PostgreSQL, MySQL, PHP, BASH.

**Gestion de errores**:
- **Token `error`**: Permite definir reglas de recuperacion en la gramatica misma
- **Recuperacion por insercion/eliminacion**: Bison puede insertar tokens faltantes o eliminar tokens sobrantes
- **Mensajes de error cripticos**: Heredado de Yacc, los mensajes suelen referirse a estados de la tabla LR
- **Depuracion con trazas**: Opcion `--debug` para seguir las acciones shift/reduce

#### 3.1.3 Flex (Fast Lexical Analyzer Generator)

**Descripcion**: Flex genera analizadores lexicos (lexers) basados en AFD. Aunque no es un parser generator, es inseparable de Bison/Yacc en la mayoria de implementaciones.

**Caracteristicas**:
- Expresiones regulares para definir tokens
- Genera codigo C/C++
- Estados/modos lexicos para contextos
- Integracion directa con Bison mediante token codes

**Gestion de errores**:
- Regla `<<EOF>>` para manejar fin de archivo
- Macro `ECHO` para caracteres no reconocidos
- Posibilidad de definir reglas catch-all para errores lexicos

#### 3.1.4 JavaCC (Java Compiler Compiler)

**Descripcion**: Generador de parsers LL(k) para Java. Similar a ANTLR pero mas antiguo y con menos caracteristicas modernas.

**Caracteristicas**:
- Parser y lexer integrados en una sola especificacion
- Lookahead de k tokens (LL(k))
- Genera codigo Java puro
- Soporte para acciones semanticas en Java

**Gestion de errores**:
- Excepciones `ParseException` con informacion de linea/columna
- Recuperacion por modo panico basico
- Mensajes de error detallados incluyendo token esperado vs encontrado

#### 3.1.5 Menhir

**Descripcion**: Generador de parsers LR(1) para OCaml. Es la evolucion de OCamlYacc con mejor manejo de conflictos y mensajes de error.

**Caracteristicas**:
- Algoritmo LR(1) puro (mas potente que LALR)
- Conflictos resueltos con precedencias explicitas
- Codigo OCaml tipado estaticamente
- Usado por el compilador de OCaml y Coq

**Gestion de errores**:
- Sistema de mensajes de error personalizables
- Deteccion de conflictos shift/reduce en tiempo de generacion
- Recuperacion mediante puntos de recuperacion explicitos

#### 3.1.6 PLY (Python Lex-Yacc)

**Descripcion**: Implementacion de Lex/Yacc puramente en Python. Usa introspeccion y reflexion para definir reglas como docstrings.

**Caracteristicas**:
- LALR(1) parser generator
- Puro Python, sin dependencias externas
- Facil de usar para prototipos rapidos
- Usado en proyectos academicos y pequenos DSLs

**Gestion de errores**:
- Funcion `p_error()` personalizable
- Recuperacion por modo panico
- Mensajes de error con pila de simbolos

### 3.2 Comparativa de Gestion de Errores

| Generador | Tipo Parser | Estrategia Principal | Calidad de Mensajes | Recuperacion Avanzada |
|:---|:---|:---|:---|:---|
| **ANTLR 4** | ALL(*) | Modo panico + tokens FOLLOW | Excelente (contextual) | Si (recuperacion inteligente en expresiones) |
| **Bison** | LALR/LR/GLR | Token `error` en gramatica | Regular (criptica) | Si (insercion/eliminacion de tokens) |
| **JavaCC** | LL(k) | Excepciones ParseException | Buena | Basica (modo panico) |
| **Menhir** | LR(1) | Puntos de recuperacion | Muy buena (personalizable) | Si (mediante %on_error_reduce) |
| **PLY** | LALR(1) | Funcion p_error() | Regular | Basica |

### 3.3 Tecnicas Comunes de Recuperacion de Errores

1. **Modo Panico (Panic Mode)**: Descartar tokens hasta encontrar uno de sincronizacion (generalmente `;`, `}`, o fin de linea). Usado por ANTLR y la mayoria de generadores.

2. **Recuperacion por Frase (Phrase Recovery)**: Saltar una cantidad fija de tokens y continuar. Menos agresivo que el modo panico.

3. **Recuperacion por Reglas de Error**: Definir producciones explicitas con el token especial `error` (caracteristico de Bison/Yacc).

4. **Correccion Local**: Insertar, eliminar o sustituir un solo token para continuar el analisis. Requiere calculo de costos.

5. **Recuperacion Semantica**: Utilizar informacion de tipos o contexto para sugerir correcciones (usado en IDEs modernos con analisis semantico integrado).

6. **Reporte de Multiples Errores**: Continuar el parsing despues del primer error para encontrar errores subsiguientes. ANTLR y Bison soportan esto nativamente.

---

## REFERENCIAS BIBLIOGRAFICAS

1. Aho, A. V., Lam, M. S., Sethi, R., & Ullman, J. D. (2006). *Compilers: Principles, Techniques, and Tools* (2nd ed.). Pearson Addison Wesley. (Libro "Dragon")

2. Parr, T. (2013). *The Definitive ANTLR 4 Reference*. Pragmatic Bookshelf.

3. Levine, J. R., Mason, T., & Brown, D. (1992). *Lex & Yacc* (2nd ed.). O'Reilly Media.

4. Tomassetti, F. (2020). "Why you should not use (f)lex, yacc and bison". Strumenta. Recuperado de: https://tomassetti.me/why-you-should-not-use-flex-yacc-and-bison/

5. Gomez-Martinez, B., & Sierra-Rodriguez, J. L. (2021). "An empirical evaluation of Lex/Yacc and ANTLR parser generation tools in computer science education". *PMC/NIH*. https://pmc.ncbi.nlm.nih.gov/articles/PMC8893623/

6. Parr, T., & Fisher, K. (2011). "LL(*): The Foundation of the ANTLR Parser Generator". *ACM SIGPLAN Notices*.

7. Wikipedia. "Comparison of parser generators". https://en.wikipedia.org/wiki/Comparison_of_parser_generators

8. GitHub Gist. "Per criterion comparison of Parser Generators and Parser Combinators" (2025). https://gist.github.com/chshersh/27844477752359735dfa41ac184d3bf2

9. Grune, D., & Jacobs, C. J. (2008). *Parsing Techniques: A Practical Guide* (2nd ed.). Springer.

10. Stack Overflow. "Advantages of Antlr (versus say, lex/yacc/bison)". https://stackoverflow.com/questions/212900/advantages-of-antlr-versus-say-lex-yacc-bison

---

## ANEXOS

### Anexo A: Estructura de Directorios del Proyecto

```
Actividad_2-3/
├── parser_ll.py
├── parser_lr.py
└── informe_pregunta2_y_3.md
```

### Anexo B: Como Ejecutar las Implementaciones

**Requisitos**: Python 3.6 o superior

**Asegúrate de estar en el directorio correcto:**
```bash
cd Actividad_2-3
```

**Ejecutar Parser LL(1)**:
```bash
python parser_ll.py
```

**Ejecutar Parser LR(1)**:
```bash
python parser_lr.py
```

**Salida esperada**: Ambos scripts procesan 6 expresiones de prueba y muestran:
- Tokens generados por el lexer
- AST construido (con evaluacion)
- Resultado numerico de la expresion
- Numero de pasos de analisis (solo LR)

---

**Nota**: Este informe corresponde a la actividad 2 del Tema 5 (Analisis Sintactico) de la asignatura Lenguaje y Compiladores, UNEG, Trimestre 2026-I.
