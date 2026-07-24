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
    