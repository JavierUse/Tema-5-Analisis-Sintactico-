import { ChangeEvent, useState } from 'react';

type StatusState = 'idle' | 'loading' | 'done';

type Chip = {
  label: string;
  tone: 'secondary' | 'card';
};

type StatItem = {
  title: string;
  value: number;
};

type TokenItem = {
  index: number;
  type: 'TK_PRINT' | 'TK_ID' | 'TK_OPERADOR' | 'TK_INT' | 'TK_IF' | 'TK_ELSE' | 'TK_STRING';
  value: string;
  original: string;
  line: number;
  col: number;
};

type ASTNode = {
  id: string;
  label: string;
  description: string;
  color: 'primary' | 'card' | 'secondary' | 'border';
  children: ASTNode[];
};

type Suggestion = {
  level: 'error' | 'advertencia' | 'info';
  text: string;
};

type Result = {
  tokens: TokenItem[];
  ast: ASTNode[];
  stats: StatItem[];
  suggestions: Suggestion[];
};

const initialCode = 'pront $x=5$; if $x>3~prnt(x)$ else prnt("no")';

const tokenPattern = /"[^"]*"|pront|prnt|if|else|[A-Za-z_]\w*|==|!=|>=|<=|[<>]=|[<>]|=|\+|\-|\*|\/|;|\(|\)|\S/g;

function analyzeCode(source: string): Result {
  tokenPattern.lastIndex = 0;
  const start = performance.now();
  const cleanedSource = source.replace(/\$/g, '');
  const suggestions: Suggestion[] = [];
  if (source.includes('$')) {
    suggestions.push({ level: 'info', text: "Se ignoraron delimitadores '$'" });
  }

  const tokens: TokenItem[] = [];
  let line = 1;
  let col = 1;
  let index = 1;
  let charPointer = 0;

  const advancePosition = (text: string) => {
    for (const char of text) {
      if (char === '\n') {
        line += 1;
        col = 1;
      } else {
        col += 1;
      }
      charPointer += 1;
    }
  };

  let match: RegExpExecArray | null;
  while ((match = tokenPattern.exec(cleanedSource)) !== null) {
    const tokenText = match[0];
    const tokenLine = line;
    const tokenCol = col;
    let type: TokenItem['type'] = 'TK_ID';
    let value = tokenText;

    if (/^"[^"]*"$/.test(tokenText)) {
      type = 'TK_STRING';
    } else if (/^\d+$/.test(tokenText)) {
      type = 'TK_INT';
    } else if (tokenText === 'pront' || tokenText === 'prnt') {
      type = 'TK_PRINT';
      value = 'print';
      suggestions.push({
        level: tokenText === 'pront' ? 'error' : 'advertencia',
        text: `${tokenText} → print`,
      });
    } else if (tokenText === 'if') {
      type = 'TK_IF';
    } else if (tokenText === 'else') {
      type = 'TK_ELSE';
    } else if (/^[<>!=]=?$/.test(tokenText) || tokenText === '=') {
      type = 'TK_OPERADOR';
    }

    tokens.push({
      index,
      type,
      value,
      original: tokenText,
      line: tokenLine,
      col: tokenCol,
    });

    index += 1;
    advancePosition(tokenText);

    const separator = cleanedSource[tokenPattern.lastIndex];
    if (separator === ' ' || separator === '\n' || separator === '\t') {
      advancePosition(separator);
      tokenPattern.lastIndex += 1;
    }
  }

  const ast: ASTNode[] = [];
  const assignment = cleanedSource.match(/\b([A-Za-z_]\w*)\s*=\s*([0-9]+)\s*;/);
  if (assignment) {
    ast.push({
      id: '1',
      label: 'Asignación',
      description: `${assignment[1]} = ${assignment[2]}`,
      color: 'primary',
      children: [],
    });
  }

  const ifIndex = tokens.findIndex((token) => token.type === 'TK_IF');
  const elseIndex = tokens.findIndex((token) => token.type === 'TK_ELSE');
  if (ifIndex !== -1) {
    const conditionTokens = tokens.slice(ifIndex + 1, elseIndex === -1 ? undefined : elseIndex).map((t) => t.value).join(' ');
    const thenPrint = tokens.slice(ifIndex + 1, elseIndex === -1 ? undefined : elseIndex).find((t) => t.type === 'TK_PRINT');
    const elsePrint = elseIndex !== -1 ? tokens.slice(elseIndex + 1).find((t) => t.type === 'TK_PRINT') : undefined;

    const children: ASTNode[] = [];
    if (thenPrint) {
      children.push({
        id: '2.1',
        label: 'Si',
        description: `print(${thenPrint.value === 'print' ? '' : thenPrint.value})`.replace('print()', 'print(x)'),
        color: 'secondary',
        children: [],
      });
    }
    if (elsePrint) {
      const elseDescription = cleanedSource.slice(cleanedSource.indexOf('else') + 4).trim();
      children.push({
        id: '2.2',
        label: 'Sino',
        description: elseDescription.startsWith('print') ? elseDescription : 'print(...)',
        color: 'border',
        children: [],
      });
    }

    ast.push({
      id: '2',
      label: 'Condicional',
      description: conditionTokens || 'if ...',
      color: 'card',
      children,
    });
  }

  const elapsed = Math.max(1, Math.round(performance.now() - start));
  const stats: StatItem[] = [
    { title: 'Tokens generados', value: tokens.length },
    { title: 'Correcciones IA', value: suggestions.length },
    { title: 'Nodos AST', value: ast.length },
    { title: 'Tiempo ms', value: elapsed },
  ];

  const uniqueSuggestions = Array.from(new Map(suggestions.map((s) => [s.text, s])).values());

  return { tokens, ast, stats, suggestions: uniqueSuggestions };
}

const badgeStyles: Record<TokenItem['type'], string> = {
  TK_PRINT: 'bg-primary/80 text-foreground',
  TK_ID: 'bg-card/80 text-foreground',
  TK_OPERADOR: 'bg-secondary/80 text-foreground',
  TK_INT: 'bg-card/80 text-foreground',
  TK_IF: 'bg-primary/80 text-foreground',
  TK_ELSE: 'bg-secondary/80 text-foreground',
  TK_STRING: 'bg-card/80 text-foreground',
};

const levelStyles: Record<Suggestion['level'], string> = {
  error: 'bg-secondary text-foreground',
  advertencia: 'bg-primary text-foreground',
  info: 'bg-card text-foreground',
};

function TreeNode({ node }: { node: ASTNode }) {
  const [open, setOpen] = useState(true);

  return (
    <div className="rounded-3xl border border-border bg-white shadow-soft p-4 mb-3">
      <button
        type="button"
        className="flex w-full items-center justify-between gap-4 text-left"
        onClick={() => setOpen(!open)}
      >
        <div>
          <div className="text-sm font-semibold text-foreground">{node.label}</div>
          <div className="text-xs text-muted-foreground">{node.description}</div>
        </div>
        <span className="text-2xl">{open ? '▾' : '▸'}</span>
      </button>
      {open && node.children.length > 0 && (
        <div className="mt-4 space-y-3 pl-4 border-l border-border">
          {node.children.map((child) => (
            <TreeNode key={child.id} node={child} />
          ))}
        </div>
      )}
    </div>
  );
}

export default function App() {
  const [codigoInput, setCodigoInput] = useState(initialCode);
  const [status, setStatus] = useState<'idle' | 'loading' | 'done'>('idle');
  const [results, setResults] = useState<Result>(() => analyzeCode(initialCode));

  const errorCount = results.suggestions.filter((s) => s.level === 'error').length;
  const warningCount = results.suggestions.filter((s) => s.level === 'advertencia').length;
  const chips: Chip[] = [
    { label: `${errorCount} errores`, tone: 'secondary' },
    { label: `${warningCount} advertencias`, tone: 'card' },
  ];

  const handleRun = () => {
    setStatus('loading');
    window.setTimeout(() => {
      setResults(analyzeCode(codigoInput));
      setStatus('done');
    }, 400);
  };

  const handleChange = (event: ChangeEvent<HTMLTextAreaElement>) => {
    setCodigoInput(event.target.value);
    if (status === 'done') {
      setStatus('idle');
    }
  };

  const isIdle = status === 'idle';

  return (
    <div className="min-h-screen bg-background text-foreground">
      <div className="mx-auto max-w-7xl px-4 py-6 md:px-8">
        <header className="sticky top-0 z-20 mb-6 rounded-[2rem] border border-border bg-card/90 p-6 shadow-soft backdrop-blur-sm">
          <div className="flex flex-col gap-4 md:flex-row md:items-center md:justify-between">
            <div className="space-y-2">
              <div className="flex flex-wrap items-center gap-3">
                <div className="h-11 w-11 rounded-2xl bg-primary shadow-soft" />
                <div>
                  <h1 className="text-2xl font-semibold">Asistente Híbrido UnegScript</h1>
                  <p className="text-sm text-muted-foreground">Universidad Nacional Experimental de Guayana</p>
                </div>
              </div>
            </div>
            <div className="flex flex-wrap items-center gap-3">
              {chips.map((chip) => (
                <span
                  key={chip.label}
                  className={`rounded-full border px-3 py-1 text-sm font-medium ${
                    chip.tone === 'secondary' ? 'border-secondary bg-secondary/70' : 'border-card bg-card/80'
                  }`}
                >
                  {chip.label}
                </span>
              ))}
              <button
                type="button"
                onClick={handleRun}
                className="rounded-full bg-primary px-5 py-2.5 text-sm font-semibold text-foreground transition hover:brightness-95"
              >
                Ejecutar Análisis
              </button>
              <button
                type="button"
                onClick={() => {
                  setCodigoInput('');
                  setResults(analyzeCode(''));
                  setStatus('idle');
                }}
                className="rounded-full border border-border bg-white px-5 py-2.5 text-sm font-semibold text-foreground transition hover:bg-muted/10"
              >
                Limpiar Página
              </button>
            </div>
          </div>
        </header>

        <section className="grid gap-6 lg:grid-cols-[1.4fr_0.9fr]">
          <article className="rounded-[2rem] border border-border bg-card p-6 shadow-soft">
            <div className="mb-4 flex items-center justify-between gap-4">
              <div className="flex items-center gap-2 text-sm text-muted-foreground">
                <span className="h-3 w-3 rounded-full bg-red-400" />
                <span className="h-3 w-3 rounded-full bg-yellow-300" />
                <span className="h-3 w-3 rounded-full bg-green-400" />
                <span>main.uneg</span>
              </div>
              <span className="rounded-full border border-border bg-white px-3 py-1 text-xs font-semibold text-muted-foreground">
                {status.toUpperCase()}
              </span>
            </div>
            <div className="grid gap-4 lg:grid-cols-[4rem_1fr]">
              <div className="space-y-2 rounded-[1.8rem] bg-white/80 p-3 text-right text-sm text-muted-foreground">
                {[...Array(8)].map((_, index) => (
                  <div key={index} className="line-number">{index + 1}</div>
                ))}
              </div>
              <div className="rounded-[1.8rem] border border-border bg-white p-4 shadow-sm">
                <textarea
                  className="editor-textarea h-80 w-full resize-none rounded-[1.5rem] border border-border bg-transparent p-4 text-sm leading-6 text-foreground outline-none"
                  value={codigoInput}
                  onChange={handleChange}
                  spellCheck="false"
                />
              </div>
            </div>

            <div className="mt-5 rounded-[1.8rem] border border-dashed border-border bg-white/80 p-4 text-sm text-muted-foreground">
              {isIdle && (
                <div className="flex items-center gap-3">
                  <span className="inline-flex h-10 w-10 items-center justify-center rounded-2xl bg-primary text-foreground">✓</span>
                  <div>
                    <p className="font-semibold text-foreground">Listo para analizar</p>
                    <p>Escribe o ajusta el código y presiona Ejecutar Análisis.</p>
                  </div>
                </div>
              )}
              {status === 'loading' && (
                <div className="grid gap-4 md:grid-cols-2">
                  <div className="h-20 animate-pulse rounded-3xl bg-border" />
                  <div className="h-20 animate-pulse rounded-3xl bg-border" />
                </div>
              )}
              {status === 'done' && (
                <div className="grid gap-4 md:grid-cols-2">
                  {results.stats.map((stat) => (
                    <div key={stat.title} className="rounded-3xl border border-border bg-background p-4 shadow-sm">
                      <p className="text-xs uppercase tracking-[0.2em] text-muted-foreground">{stat.title}</p>
                      <p className="mt-3 text-3xl font-semibold text-foreground">{stat.value}</p>
                    </div>
                  ))}
                </div>
              )}
            </div>
          </article>

          <aside className="space-y-6">
            <div className="rounded-[2rem] border border-border bg-card p-6 shadow-soft">
              <h2 className="mb-4 text-lg font-semibold">Estadísticas rápidas</h2>
              <div className="grid gap-4 sm:grid-cols-2">
                {results.stats.map((item) => (
                  <div key={item.title} className="rounded-3xl border border-border bg-white p-4">
                    <p className="text-xs uppercase tracking-[0.15em] text-muted-foreground">{item.title}</p>
                    <p className="mt-3 text-2xl font-semibold text-foreground">{item.value}</p>
                  </div>
                ))}
              </div>
            </div>
            <div className="rounded-[2rem] border border-border bg-card p-6 shadow-soft">
              <h2 className="mb-4 text-lg font-semibold">Sugerencias IA</h2>
              <div className="space-y-3">
                {results.suggestions.map((sug) => (
                  <div key={sug.text} className={`rounded-3xl border border-border p-4 ${levelStyles[sug.level]}`}>
                    <div className="mb-2 text-xs uppercase tracking-[0.15em] text-muted-foreground">{sug.level}</div>
                    <p className="font-semibold">{sug.text}</p>
                  </div>
                ))}
              </div>
            </div>
          </aside>
        </section>

        <section className="mt-8 grid gap-6 xl:grid-cols-[1.2fr_0.8fr]">
          <div className="rounded-[2rem] border border-border bg-card p-6 shadow-soft">
            <h2 className="mb-4 text-lg font-semibold">Tokens Corregidos</h2>
            <div className="overflow-hidden rounded-3xl border border-border bg-white">
              <table className="min-w-full text-left text-sm">
                <thead className="bg-background text-muted-foreground">
                  <tr>
                    <th className="px-4 py-3">#</th>
                    <th className="px-4 py-3">Tipo</th>
                    <th className="px-4 py-3">Valor</th>
                    <th className="px-4 py-3">Corrección</th>
                    <th className="px-4 py-3">Línea</th>
                  </tr>
                </thead>
                <tbody>
                  {results.tokens.map((token) => (
                    <tr key={token.index} className="border-t border-border">
                      <td className="px-4 py-3 text-muted-foreground">{token.index}</td>
                      <td className={`px-4 py-3 text-xs font-semibold uppercase ${badgeStyles[token.type as keyof typeof badgeStyles]}`}>
                        {token.type}
                      </td>
                      <td className="px-4 py-3 font-mono text-sm text-foreground">{token.value}</td>
                      <td className="px-4 py-3 text-sm text-muted-foreground">
                        {token.original !== token.value ? (
                          <span>
                            <span className="line-through text-secondary">{token.original}</span>{' '}
                            <span className="text-green-900">{token.value}</span>
                          </span>
                        ) : (
                          <span className="text-muted-foreground">—</span>
                        )}
                      </td>
                      <td className="px-4 py-3 text-muted-foreground">{token.line}:{token.col}</td>
                    </tr>
                  ))}
                </tbody>
              </table>
            </div>
          </div>

          <div className="rounded-[2rem] border border-border bg-card p-6 shadow-soft">
            <h2 className="mb-4 text-lg font-semibold">Árbol de Sintaxis Abstracta</h2>
            <div className="space-y-3">
              {results.ast.map((node) => (
                <TreeNode key={node.id} node={node} />
              ))}
            </div>
          </div>
        </section>

        <footer className="mt-10 rounded-[2rem] border border-border bg-card p-6 text-sm text-muted-foreground">
          Universidad Nacional Experimental de Guayana • v2.4.0
        </footer>
      </div>
    </div>
  );
}
