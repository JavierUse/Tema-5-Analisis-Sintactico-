/*
 * ============================================================================
 * Gramática: YamlDocker.g4
 * ----------------------------------------------------------------------------
 * Subconjunto de YAML orientado exclusivamente a la descripción de archivos
 * docker-compose.yml, con foco en la sección "services" (imagen, puertos,
 * variables de entorno) y la sección "networks" (driver de red).
 *
 * NOTA DE DISEÑO — Simplificación de contexto sobre indentaciones
 * ----------------------------------------------------------------------------
 * YAML real es un lenguaje SENSIBLE A LA INDENTACIÓN (off-side rule), lo cual
 * requiere en un lexer "puro" un mecanismo de pila de indentación (similar al
 * par INDENT/DEDENT de Python) para emitir tokens sintéticos cuando el nivel
 * de sangría aumenta o disminuye. ANTLR4 no soporta esto de forma nativa sin
 * recurrir a un TokenFactory personalizado o a un paso de preprocesamiento.
 *
 * Para mantener el foco del experimento en la MEDICIÓN DE TIEMPOS de
 * lexing/parsing entre lenguajes (y no en la implementación de un lexer de
 * indentación completo), esta gramática adopta una simplificación:
 *
 *   1. Los espacios y tabs al inicio de línea se DESCARTAN (canal HIDDEN /
 *      skip) y NO se usan como delimitadores estructurales.
 *   2. La estructura jerárquica (qué "properties" pertenecen a qué servicio,
 *      qué items de lista pertenecen a qué propiedad) se infiere de forma
 *      SECUENCIAL usando palabras clave de sección (services, networks,
 *      image, ports, environment, driver) y separadores explícitos
 *      (':', '-', NEWLINE), en lugar de la profundidad de sangría real.
 *   3. Esto implica que el subconjunto aceptado es más rígido que YAML
 *      general: se asume que cada docker-compose.yml de prueba respeta un
 *      orden y una sangría "canónica" de 2 espacios (generada de forma
 *      consistente por scripts/generate_dataset.py), pero el lexer/parser
 *      NUNCA valida esa sangría — solo el orden de las palabras clave.
 *
 * Esta simplificación es intencional y está documentada aquí para que el
 * lector no interprete la ausencia de reglas de indentación como un olvido.
 * ============================================================================
 */
grammar YamlDocker;

// ============================================================================
// REGLAS DEL PARSER
// ============================================================================

document
    : NEWLINE* version_line? services_block? networks_block? NEWLINE* EOF
    ;

version_line
    : VERSION_KEY COLON value NEWLINE
    ;

services_block
    : SERVICES_KEY COLON NEWLINE service_entry+
    ;

service_entry
    : NAME COLON NEWLINE service_prop+
    ;

service_prop
    : image_prop
    | ports_prop
    | environment_prop
    | networks_ref_prop
    ;

image_prop
    : IMAGE_KEY COLON value NEWLINE
    ;

ports_prop
    : PORTS_KEY COLON NEWLINE list_item+
    ;

environment_prop
    : ENVIRONMENT_KEY COLON NEWLINE list_item+
    ;

networks_ref_prop
    : NETWORKS_KEY COLON NEWLINE list_item+
    ;

networks_block
    : NETWORKS_KEY COLON NEWLINE network_entry+
    ;

network_entry
    : NAME COLON NEWLINE network_prop*
    ;

network_prop
    : DRIVER_KEY COLON value NEWLINE
    ;

list_item
    : DASH value NEWLINE
    ;

value
    : STRING
    | NUMBER
    ;

// ============================================================================
// REGLAS DEL LEXER
// ============================================================================

// Palabras clave (deben declararse ANTES de la regla genérica NAME para que
// ANTLR las resuelva por prioridad de declaración ante un empate de longitud)
VERSION_KEY     : 'version';
SERVICES_KEY    : 'services';
NETWORKS_KEY    : 'networks';
IMAGE_KEY       : 'image';
PORTS_KEY       : 'ports';
ENVIRONMENT_KEY : 'environment';
DRIVER_KEY      : 'driver';

COLON : ':';
DASH  : '-';

// Un STRING captura cualquier valor "de línea": nombres de imagen con tag
// (nginx:1.21-alpine), mapeos de puertos (8080:80), pares clave=valor de
// environment (KEY=value), o literales entre comillas. Se permite casi
// cualquier caracter imprimible salvo NEWLINE, ':' seguido de espacio (que
// en YAML real indicaría un nuevo mapeo) y '#' (comentarios).
STRING
    : '"' (~["\r\n])* '"'
    | '\'' (~['\r\n])* '\''
    | (~[ \t\r\n#:] | ':' ~[ \t\r\n])+
    ;

NUMBER
    : [0-9]+ ('.' [0-9]+)?
    ;

NAME
    : [a-zA-Z_][a-zA-Z0-9_.-]*
    ;

NEWLINE
    : ('\r'? '\n')+
    ;

// Espacios/tabs de indentación y espacios inter-token: se descartan por
// completo, tal como se explica en la nota de diseño anterior.
WS
    : [ \t]+ -> skip
    ;

COMMENT
    : '#' ~[\r\n]* -> skip
    ;
