#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int s, d, t;
} A;

int n, i, j, d[30001], s;
A a[20000];

int c(const void *x, const void *y) {
  if (((A*) x)->d < ((A*) y)->d)
    return -1;
  if (((A*) x)->d == ((A*) y)->d)
    return 0;
  return 1;
}

int main() {
  scanf("%d", &n);
  for (i = 0; i != n; ++i)
    scanf("%d%d%d", &a[i].s, &a[i].d, &a[i].t);
  qsort(a, n, sizeof(A), c);
  s = 0;
  for (i = 0; i != n; ++i)
    for (j = a[i].d; j >= a[i].t; j--)
      if (d[j] < d[j - a[i].t] + a[i].s) {
        d[j] = d[j - a[i].t] + a[i].s;
        if (s < d[j])
          s = d[j];
      }
  printf("%d", s);
  return 0;
}
