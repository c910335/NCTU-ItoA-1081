#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int t, d;
} M;

int n, a, b, i, t;
M m[1000000];

int cmp(const void *x, const void *y) {
  if (((M*) x)->t == ((M*) y)->t)
    return ((M*) x)->d - ((M*) y)->d;
  return ((M*) x)->t - ((M*) y)->t;
}

int main() {
  scanf("%d", &n);
  n <<= 1;
  for (i = 0; i != n; ++i) {
    scanf("%d%d", &a, &b);
    m[i].t = a;
    m[i++].d = 1;
    m[i].t = b;
    m[i].d = -1;
  }
  a = b = 1;
  qsort(m, n, sizeof(M), cmp);
  for (i = 1; i != n; ++i) {
    a += m[i].d;
    if (b < a) {
      b = a;
      t = i;
    }
  }
  printf("%d %d", m[t].t, b);
  return 0;
}
