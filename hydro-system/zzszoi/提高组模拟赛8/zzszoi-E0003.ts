import * as fs from 'fs';

const INF = 0x3f3f3f3f;
const MAXV = 400;
const SIZE = MAXV + 5;

const input = fs.readFileSync('magic.in', 'utf-8');
const tokens = input.trim().split(/\s+/).map(Number);
let idx = 0;

const n = tokens[idx++];
const m = tokens[idx++]!;

const s: number[] = new Array(n + 1);
for (let i = 1; i <= n; i++) {
  s[i] = tokens[idx++]!;
}

const t: number[] = new Array(n + 1);
for (let i = 1; i <= n; i++) {
  t[i] = tokens[idx++]!;
}

const p: number[][] = Array.from({ length: SIZE }, () =>
  new Array<number>(SIZE).fill(INF)
);

for (let _ = 0; _ < m; _++) {
  const a = tokens[idx++]!;
  const b = tokens[idx++]!;
  const c = tokens[idx++]!;
  p[a][b] = Math.min(p[a][b], c);
}

for (let k = 1; k <= MAXV; k++) {
  p[k][k] = 0;
  for (let i = 1; i <= MAXV; i++) {
    for (let j = 1; j <= MAXV; j++) {
      const viaK = p[i][k] + p[k][j];
      if (viaK < p[i][j]) {
        p[i][j] = viaK;
      }
    }
  }
}

let ans = 0;
for (let i = 1; i <= n; i++) {
  let best = INF;
  for (let j = 1; j <= MAXV; j++) {
    const cost = p[s[i]][j] + p[t[i]][j];
    if (cost < best) best = cost;
  }
  if (best === INF) {
    fs.writeFileSync('magic.out', '-1');
    process.exit(0);
  }
  ans += best;
}

fs.writeFileSync('magic.out', ans.toString());
