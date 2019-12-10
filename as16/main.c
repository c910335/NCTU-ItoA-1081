#include <stdio.h>

int n, m, a, b, c[100000], p[100000], i, j, t;

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
  scanf("%d%d", &n, &m);
  for (i = 1; i != n; ++i)
    p[i] = i;
  while (m--) {
    scanf("%d%d", &a, &b);
    a = f(a - 1);
    b = f(b - 1);
    if (a != b) {
      if (c[a] > c[b]) {
        p[b] = a;
        c[a] += c[b] + 1;
      } else {
        p[a] = b;
        c[b] += c[a] + 1;
      }
    }
  }
  printf("%d", c[f(0)]);
  for (i = 1; i != n; ++i)
    printf(" %d", c[f(i)]);
  return 0;
}
