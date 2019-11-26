#include <stdio.h>
#include <stdlib.h>
#define swap(x,y) z=x;x=y;y=z

typedef struct {
  int d, t;
} A;

int n, i, c, j, k, z;
long long t;
A a[1000000];

int cmp(const void *a, const void *b) {
  if (((A*)a)->d < ((A*)b)->d)
    return -1;
  if (((A*)a)->d == ((A*)b)->d)
    return 0;
  return 1;
}

void up() {
  for (j = c - 1; j > 0 && a[(j - 1) >> 1].t < a[j].t; j = (j - 1) >> 1) {
    swap(a[(j - 1) >> 1].t, a[j].t);
  }
}

void down() {
  j = 0;
  k = 1;
  while (k < c) {
    if (k + 1 < c && a[k + 1].t > a[k].t)
      k++;
    if (a[j].t > a[k].t)
      break;
    swap(a[j].t, a[k].t);
    j = k;
    k = (k << 1) + 1;
  }
}

int main() {
  scanf("%d", &n);
  for (i = 0; i != n; ++i)
    scanf("%d%d", &a[i].d, &a[i].t);
  qsort(a, n, sizeof(A), cmp);
  c = 0;
  for (i = 0; i != n; ++i) {
    t += a[i].t;
    a[c].t = a[i].t;
    c++;
    if (t > a[i].d) {
      up();
      t -= a[0].t;
      c--;
      a[0] = a[c];
      down();
    } else
      up();
  }
  printf("%d", c);
  return 0;
}
