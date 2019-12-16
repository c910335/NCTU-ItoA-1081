#include <stdio.h>
#include <stdlib.h>

typedef struct E {
  int t, l;
  struct E *n;
} E;

int n, i, a, b, l;
E *g[100000], *t;
long long s, d, td;

void add() {
  t = (E*) malloc(sizeof(E));
  t->t = a;
  t->l = l;
  t->n = g[b];
  g[b] = t;
  t = (E*) malloc(sizeof(E));
  t->t = b;
  t->l = l;
  t->n = g[a];
  g[a] = t;
}

long long h(int c, int p) {
  E *t;
  long long m = 0, k = 0;
  for (t = g[c]; t; t = t->n)
    if (t->t != p) {
      td = h(t->t, c) + t->l;
      if (td >= m) {
        k = m;
        m = td;
      } else if (td > k)
        k = td;
    }
  if (d < m + k)
    d = m + k;
  return m;
}

int main() {
  scanf("%d", &n);
  for (i = 1; i != n; ++i) {
    scanf("%d%d%d", &a, &b, &l);
    a--;
    b--;
    s += l;
    add();
  }
  h(0, 0);
  printf("%lld", s * 2 - d);
}
