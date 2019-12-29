#include <stdio.h>
#include <stdlib.h>

typedef struct E {
  int t;
  struct E *n;
} E;

int n, i, a, b, m[100001];
E *g[100000], *t;

void add() {
  t = malloc(sizeof(E));
  t->t = a;
  t->n = g[b];
  g[b] = t;
  t = malloc(sizeof(E));
  t->t = b;
  t->n = g[a];
  g[a] = t;
}

void dfs(int c, int f) {
  for (E *t = g[c]; t; t = t->n)
    if (t->t != f)
      dfs(t->t, c);
  if (!(m[c] || m[f])) {
    m[c] = m[f] = 1;
    a++;
  }
}

int main() {
  scanf("%d", &n);
  for (i = 1; i != n; ++i) {
    scanf("%d%d", &a, &b);
    add();
  }
  m[n] = 1;
  a = 0;
  dfs(0, n);
  printf("%d", a);
  return 0;
}
