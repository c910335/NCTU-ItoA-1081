#include <stdio.h>
#include <stdlib.h>

typedef struct E {
  int t;
  struct E *n;
} E;

int n, i, a, b, m, r;
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
  int s = 0, e = 0;
  for (E *t = g[c]; t; t = t->n)
    if (t->t != f) {
      dfs(t->t, c);
      if (!r)
        e = 1;
      s += m;
    }
  s += e;
  m = s;
  r = e;
}

int main() {
  scanf("%d", &n);
  for (i = 1; i != n; ++i) {
    scanf("%d%d", &a, &b);
    add();
  }
  dfs(0, 0);
  printf("%d", m);
  return 0;
}
