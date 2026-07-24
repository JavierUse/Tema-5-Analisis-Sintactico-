from constructor_ast import NodoAsignacion, NodoCondicional, NodoImpresion


class ParserRecursivo:
    def __init__(self, tokens):
        # tokens: lista de tuplas (tipo, valor)
        self.tokens = tokens
        self.posicion = 0
        self.sugerencias_sintaxis = []

    def mirar_actual(self):
        if self.posicion < len(self.tokens):
            return self.tokens[self.posicion]
        return (None, None)

    def consumir(self, tipo_esperado=None):
        token_actual, valor_actual = self.mirar_actual()
        if token_actual is None:
            return None
        if tipo_esperado and token_actual != tipo_esperado:
            # Simulación de asistencia de IA ante fallo de sintaxis
            self.sugerencias_sintaxis.append(
                f"Sugerencia Sintáctica IA: Se esperaba {tipo_esperado} pero se encontró '{valor_actual}'[cite: 1]"
            )
        self.posicion += 1
        return valor_actual

    parsear = property(lambda self: self.analizar())

    def analizar(self):
        nodos = []
        # Asegurarse de que tokens tengan forma (tipo, valor)
        while self.posicion < len(self.tokens):
            tipo, valor = self.mirar_actual()

            # Normalizar None
            if valor is None:
                self.posicion += 1
                continue

            # Impresión (permitir variantes erróneas)
            if valor in ("pront", "prnt", "print"):
                # Mirar patrón: si viene 'ID = INT ;' probablemente el 'print' es erróneo
                # y la intención real era una asignación. En ese caso, producir una Asignacion.
                # Si no, comportarse como impresión normal.
                # Guardar posición para lookahead
                inicio = self.posicion
                self.consumir()  # consumir el token print/pront/prnt
                # lookahead seguro
                la_tipo = None
                la_val = None
                la2_tipo = None
                la2_val = None
                if self.posicion < len(self.tokens):
                    la_tipo, la_val = self.mirar_actual()
                if self.posicion + 1 < len(self.tokens):
                    la2_tipo, la2_val = self.tokens[self.posicion + 1]

                if la_tipo == 'TK_ID' and la2_tipo == 'TK_OPERADOR':
                    # consumir ID, operador, y posible valor
                    var = self.consumir()
                    op = self.consumir()
                    val = None
                    if self.posicion < len(self.tokens):
                        val = self.consumir()
                    nodos.append(NodoAsignacion(var, val))
                else:
                    # tratar como impresión clásica
                    args = []
                    while self.posicion < len(self.tokens) and self.mirar_actual()[1] != ';':
                        args.append(self.consumir())
                    nodos.append(NodoImpresion(" ".join([a for a in args if a is not None])))

            # Asignación simple: ID = VAL
            elif tipo == "TK_ID":
                var = self.consumir()
                # consumir operador si está
                op = None
                if self.mirar_actual()[0] == 'TK_OPERADOR':
                    op = self.consumir()
                val = None
                if self.posicion < len(self.tokens):
                    val = self.consumir()
                nodos.append(NodoAsignacion(var, val))

            # Condicional
            elif valor == "if":
                self.consumir()
                cond_partes = []
                while self.posicion < len(self.tokens) and self.mirar_actual()[1] not in ['else', ';', '~']:
                    cond_partes.append(self.consumir())

                # Consumir separador si existe ('~')
                if self.posicion < len(self.tokens) and self.mirar_actual()[1] == '~':
                    self.consumir()

                cuerpo_if = None
                if self.posicion < len(self.tokens) and self.mirar_actual()[1] in ["print", "prnt", "pront"]:
                    self.consumir()
                    args_if = []
                    while self.posicion < len(self.tokens) and self.mirar_actual()[1] not in ['else', ';']:
                        args_if.append(self.consumir())
                    cuerpo_if = NodoImpresion(" ".join([a for a in args_if if a is not None]))

                cuerpo_else = None
                if self.posicion < len(self.tokens) and self.mirar_actual()[1] == 'else':
                    self.consumir()
                    # Si el else tiene un print, consumirlo y tomar sus argumentos
                    if self.posicion < len(self.tokens) and self.mirar_actual()[1] in ["print", "prnt", "pront"]:
                        self.consumir()
                        args_else = []
                        while self.posicion < len(self.tokens) and self.mirar_actual()[1] != ';':
                            args_else.append(self.consumir())
                        cuerpo_else = NodoImpresion(" ".join([a for a in args_else if a is not None]))
                    else:
                        args_else = []
                        while self.posicion < len(self.tokens) and self.mirar_actual()[1] != ';':
                            args_else.append(self.consumir())
                        cuerpo_else = NodoImpresion(" ".join([a for a in args_else if a is not None]))

                nodos.append(NodoCondicional(" ".join([c for c in cond_partes if c is not None]), cuerpo_if, cuerpo_else))

            else:
                # avanzar para evitar bucles infinitos
                self.posicion += 1

        return nodos, self.sugerencias_sintaxis