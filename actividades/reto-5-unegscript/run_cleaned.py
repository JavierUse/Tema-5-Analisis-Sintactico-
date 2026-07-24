import re

class NodoAST:
    pass

class NodoAsignacion(NodoAST):
    def __init__(self, variable, valor):
        self.variable = variable
        self.valor = valor
    def __repr__(self):
        return f"Asignacion(Var: {self.variable}, Valor: {self.valor})"

class NodoCondicional(NodoAST):
    def __init__(self, condicion, cuerpo_if, cuerpo_else=None):
        self.condicion = condicion
        self.cuerpo_if = cuerpo_if
        self.cuerpo_else = cuerpo_else
    def __repr__(self):
        return f"Condicional(Si: {self.condicion} -> {self.cuerpo_if}, Sino: {self.cuerpo_else})"

class NodoImpresion(NodoAST):
    def __init__(self, expresion):
        self.expresion = expresion
    def __repr__(self):
        return f"Impresion({self.expresion})"


def calcular_similitud(a,b):
    import difflib
    return difflib.SequenceMatcher(None,a,b).ratio()


def analizar_codigo(codigo_prueba):
    TOKENS_VALIDOS = {'if':'TK_IF','else':'TK_ELSE','print':'TK_PRINT'}
    sugerencias = []
    tokens = []

    patron = r"(==|!=|>=|<=|[a-zA-Z_]\w*|\d+|[\"\'].*?[\"\']|[^\s])"
    elementos = re.findall(patron, codigo_prueba)

    for lexema in elementos:
        if lexema.strip() == '':
            continue
        # Ignorar delimitadores residuales
        if lexema == '$':
            sugerencias.append(f"Sugerencia (ignorar delimitador): '{lexema}' removed")
            continue
        if lexema in TOKENS_VALIDOS or re.match(r'^[a-zA-Z_]\w*$', lexema):
            if lexema in TOKENS_VALIDOS:
                token_tipo = TOKENS_VALIDOS[lexema]
                token_valor = lexema
            else:
                token_tipo = 'TK_ID'
                token_valor = lexema
            tokens.append((token_tipo, token_valor))
        elif re.match(r'^\d+$', lexema):
            tokens.append(('TK_INT', lexema))
        elif lexema in ['=','>','<','+','-','*','/']:
            tokens.append(('TK_OPERADOR', lexema))
        elif lexema in [';','(',')','{','}','~',':']:
            tokens.append(('TK_SIMBOLO', lexema))
        elif lexema.startswith('"') and lexema.endswith('"'):
            tokens.append(('TK_STRING', lexema))
        else:
            # similitud con keywords
            mejor = None
            maxr = 0.0
            for cand in TOKENS_VALIDOS.keys():
                r = calcular_similitud(lexema, cand)
                if r > maxr:
                    maxr = r; mejor = cand
            if maxr < 0.8:
                sugerido = mejor if mejor else lexema
                sugerencias.append(f"Sugerencia (IA Fallback < 0.8): '{lexema}' → '{sugerido}'")
                tokens.append(('TK_CORREGIDO_IA', sugerido))
            else:
                tokens.append(('TK_DESCONOCIDO', lexema))

    # Parseo simple
    pos = 0
    nodos = []
    def mirar():
        nonlocal pos
        if pos < len(tokens):
            return tokens[pos]
        return (None,None)
    def consumir():
        nonlocal pos
        t = tokens[pos][1]
        pos += 1
        return t

    while pos < len(tokens):
        tipo, valor = mirar()
        if valor == 'print':
            consumir()
            args = []
            while pos < len(tokens) and tokens[pos][1] != ';':
                args.append(consumir())
            nodos.append(NodoImpresion(' '.join(args)))
        elif tipo == 'TK_ID':
            var = consumir()
            op = consumir() if pos < len(tokens) else None
            val = consumir() if pos < len(tokens) else None
            nodos.append(NodoAsignacion(var, val))
        elif valor == 'if':
            consumir()
            cond = []
            while pos < len(tokens) and tokens[pos][1] not in ['else',';','~',':']:
                cond.append(consumir())
            if pos < len(tokens) and tokens[pos][1] == '~':
                consumir()
            if pos < len(tokens) and tokens[pos][1] == ':':
                consumir()
            cuerpo_if = None
            if pos < len(tokens) and tokens[pos][1] == 'print':
                consumir()
                args_if = []
                while pos < len(tokens) and tokens[pos][1] not in ['else',';']:
                    args_if.append(consumir())
                cuerpo_if = NodoImpresion(' '.join(args_if))
            cuerpo_else = None
            if pos < len(tokens) and tokens[pos][1] == 'else':
                consumir()
                # consumir posible ':'
                if pos < len(tokens) and tokens[pos][1] == ':':
                    consumir()
                args_else = []
                while pos < len(tokens) and tokens[pos][1] != ';':
                    args_else.append(consumir())
                cuerpo_else = NodoImpresion(' '.join(args_else))
            nodos.append(NodoCondicional(' '.join(cond), cuerpo_if, cuerpo_else))
        else:
            pos += 1
    return tokens, nodos, sugerencias

if __name__ == '__main__':
    codigo = 'x = 5 ; if x > 3 ~ print ( x ) else print ( "no" )'
    tokens, nodos, sugerencias = analizar_codigo(codigo)
    print('--- TOKENS CORREGIDOS ---')
    for t in tokens:
        print(t)
    print('\n--- AST ---')
    for n in nodos:
        print(n)
    print('\n--- SUGERENCIAS IA ---')
    for s in sugerencias:
        print('-', s)
