#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int u, v, i;
} C;

int cc(const void *a, const void *b) {
  C *x = (C*) a;
  C *y = (C*) b;
  if (x->u == y->u) {
    if (x->v < y->v)
      return -1;
    if (x->v == y->v)
      return 0;
    return 1;
  }
  if (x->u < y->u)
    return -1;
  return 1;
}

int ci(const void *a, const void *b) {
  if (*(int*) a < *(int*) b)
    return -1;
  return 1;
}

int m, i, a[1500001], u, v;
C c[1500000];

int main() {
  scanf("%d", &m);
  for (i = 0; i != m; ++i) {
    scanf("%d%d", &c[i].u, &c[i].v);
    c[i].i = i;
  }
  qsort(c, m, sizeof(C), cc);
  i = m - 1;
  u = c[i].u;
  v = c[i].v;
  a[c[i].i] = c[i].i + 1;
  while (i--)
    if (c[i].v > v || (c[i].u == u && c[i].v == v)) {
      u = c[i].u;
      v = c[i].v;
      a[c[i].i] = c[i].i + 1;
    }
  for (i = 0; i != m; ++i)
    if (a[i])
      printf("%d ", a[i]);
  return 0;
}
