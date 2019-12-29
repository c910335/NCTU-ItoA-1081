#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct E {
  int c, t;
  struct E *n, *p;
} E;

int n, m, r, a, b, i, d[2002], q[2002], h, t;
E *g[2002], *u, *v, *l[2002];

void add(int f, int t) {
  u = malloc(sizeof(E));
  u->c = 1;
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
  memset(d + 1, 0, sizeof(int) * m);
  h = 0;
  t = 1;
  while (t > h) {
    b = q[h++];
    for (u = g[b]; u; u = u->n)
      if (!d[u->t] && u->c) {
        d[u->t] = d[b] + 1;
        q[t++] = u->t;
      }
  }
  return d[1];
}

int dfs(int c) {
  if (c == 1)
    return 1;
  for (; l[c]; l[c] = l[c]->n)
    if (d[l[c]->t] == d[c] + 1 && l[c]->c && dfs(l[c]->t)) {
      l[c]->c--;
      l[c]->p->c++;
      return 1;
    }
  return 0;
}

int main() {
  scanf("%d%d%d", &n, &m, &r);
  n += 2;
  for (i = 2; i != n; ++i)
    add(0, i);
  m += n;
  for (; i != m; ++i)
    add(i, 1);
  m--;
  while (r--) {
    scanf("%d%d", &a, &b);
    add(a + 2, b + n);
  }
  a = 0;
  d[0] = 1;
  while (bfs()) {
    for (i = 0; i <= m; ++i)
      l[i] = g[i];
    while (dfs(0))
      a++;
  }
  printf("%d", a);
  return 0;
}
