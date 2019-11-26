#include <stdio.h>

int n, i;
long long a[500000], d[2], t;

int main() {
  scanf("%d", &n);
  for (i = 0; i != n; ++i)
    scanf("%lld", a + i);
  d[1] = a[1];
  for (i = 2; i < n; ++i) {
    if (a[i] + d[i & 1] > d[(i + 1) & 1])
      d[i & 1] += a[i];
    else
      d[i & 1] = d[(i + 1) & 1];
  }
  t = d[(i + 1) & 1];
  d[0] = a[0];
  if (a[1] > a[0])
    d[1] = a[1];
  else
    d[1] = a[0];
  for (i = 2; i < n - 1; ++i) {
    if (a[i] + d[i & 1] > d[(i + 1) & 1])
      d[i & 1] += a[i];
    else
      d[i & 1] = d[(i + 1) & 1];
  }
  if (d[(i + 1) & 1] > t)
    t = d[(i + 1) & 1];
  printf("%lld", t);
  return 0;
}
