#include <stdio.h>

int n, m, s, t, d[50001], i;

int main() {
  scanf("%d%d", &n, &m);
  while (n--) {
    scanf("%d%d", &s, &t);
    for (i = m; i >= t; --i)
      if (d[i - t] + s > d[i])
        d[i] = d[i - t] + s;
  }
  printf("%d", d[m]);
  return 0;
}
