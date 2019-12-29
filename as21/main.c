#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct E {
  int c, t;
  struct E *n, *p;
} E;

int n, m, a, b, i, d[300], q[300], f, af, h, t, c;
E *g[300], *u, *v, *l[300];

void add() {
  u = malloc(sizeof(E));
  u->c = 1;
  u->t = b;
  u->n = g[a];
  g[a] = u;
  v = malloc(sizeof(E));
  v->c = 1;
  v->t = a;
  v->n = g[b];
  g[b] = v;
  u->p = v;
  v->p = u;
}

int bfs() {
  memset(d + 1, 0, sizeof(int) * n);
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
  return d[n];
}

int dfs(int c) {
  if (c == n)
    return 1;
  for (; l[c]; l[c] = l[c]->n)
    if(d[l[c]->t] == d[c] + 1 && l[c]->c && dfs(l[c]->t)) {
      l[c]->c--;
      l[c]->p->c++;
      return 1;
    }
  return 0;
}

int main() {
  scanf("%d%d", &n, &m);
  n--;
  while (m--) {
    scanf("%d%d", &a, &b);
    add();
  }
  d[0] = 1;
  while (bfs()) {
    for (i = 0; i <= n; ++i)
      l[i] = g[i];
    while(dfs(0))
      f++;
  }
  printf("%d", f);
  return 0;
}
