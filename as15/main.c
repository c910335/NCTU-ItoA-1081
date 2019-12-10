#include <stdio.h>
#include <stdlib.h>
#define SIZE 300000

typedef struct {
  int s, d;
} A;

int n, i, j, k, m, t, p[SIZE + 1];
long long s;
A a[SIZE];

int c(const void *x, const void *y) {
  if (((A*) x)->s < ((A*) y)->s)
    return 1;
  if (((A*) x)->s > ((A*) y)->s)
    return -1;
  return 0;
}

int f(int x) {
  for (j = x; j != p[j]; j = p[j]);
  while (x != p[x]) {
    t = x;
    x = p[x];
    p[t] = j;
  }
  return j;
}

int main() {
  scanf("%d", &n);
  for (i = 0; i != n; ++i) {
    scanf("%d%d", &a[i].s, &a[i].d);
    p[i] = i;
  }
  m = n;
  qsort(a, n, sizeof(A), c);
  for (i = 0; i != n; ++i)
    if (a[i].d >= m) {
      s += a[i].s;
      m--;
    } else if ((k = f(a[i].d))) {
      s += a[i].s;
      p[k] = f(k - 1);
    }
  printf("%lld", s);
  return 0;
}
