import traceback
try:
    ns = {}
    with open('analizador_sintactico.py', 'r', encoding='utf-8') as f:
        code = f.read()
    print('FILE PREVIEW:\n', code[:400])
    print('Contains ParserRecursivo?', 'ParserRecursivo' in code)
    exec(compile(code, 'analizador_sintactico.py', 'exec'), ns)
    print('Executed OK. Symbols:', [k for k in ns.keys() if not k.startswith('__')])
except Exception:
    traceback.print_exc()
