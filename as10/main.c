#include <stdio.h>

int n, i, a[300], s, m, j, d[150001];

int main() {
  scanf("%d", &n);
  for (i = 0; i != n; ++i) {
    scanf("%d", a + i);
    s += a[i];
  }
  m = s >> 1;
  d[0] = 1;
  for (i = 0; i != n; ++i)
    for (j = m; j >= a[i]; --j)
      if (d[j - a[i]])
        d[j] = 1;
  for (i = m; ; --i)
    if (d[i]) {
      printf("%d", s - (i << 1));
      break;
    }
  return 0;
}
