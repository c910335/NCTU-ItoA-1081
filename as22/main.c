#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(x, y) x < y ?x : y

typedef struct E {
  int c, t;
  struct E *n, *p;
} E;

int n, m, i, j, s, c, d[262], f, af, q[262], h, t;
E *g[262], *u, *v, *l[262];

void add(int f, int t, int c) {
  u = malloc(sizeof(E));
  u->c = c;
  u->t = t;
  u->n = g[f];
  g[f] = u;
  v = malloc(sizeof(E));
  v->c = 0;
  v->t = f;
  v->n = g[t];
  g[t] = v;
  u->p = v;
  v->p = u;
}

int bfs() {
  memset(d + 1, 0, sizeof(int) * (n - 1));
  h = 0;
  t = 1;
  while (t > h) {
    c = q[h++];
    for (u = g[c]; u; u = u->n)
      if (!d[u->t] && u->c) {
        d[u->t] = d[c] + 1;
        q[t++] = u->t;
      }
  }
  return d[1];
}

int dfs(int c, int f) {
  if (c == 1)
    return f;
  int nf = 0, af;
  for (E *t = l[c]; t; l[c] = t = t->n) {
    if (d[t->t] != d[c] + 1 || !t->c)
      continue;
    if ((af = dfs(t->t, min(f, t->c)))) {
      t->c -= af;
      t->p->c += af;
      nf += af;
      f -= af;
      if (!f)
        break;
    }
  }
  return nf;
}

int main() {
  scanf("%d%d", &n, &m);
  n += 2;
  for (i = 2; i != n; ++i) {
    scanf("%d", &c);
    s += c;
    add(i, 1, c);
  }
  for (; i != n + m; ++i) {
    scanf("%d", &c);
    add(0, i, c);
  }
  for (i = 2; i != n; ++i) {
    scanf("%d", &c);
    while (c--) {
      scanf("%d", &j);
      add(j + n, i, INT_MAX);
    }
  }
  n += m;
  d[0] = 1;
  while (bfs()) {
    for (i = 0; i != n; ++i)
      l[i] = g[i];
    while ((af = dfs(0, INT_MAX)))
      f += af;
  }
  printf("%d", s - f);
  return 0;
}
