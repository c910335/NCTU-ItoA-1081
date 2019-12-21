#include <stdio.h>
#include <limits.h>

#define max(a, b) a > b ? a : b

int n, m, q, i, j, k, g[500][500];

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (i = 0; i != n; ++i)
    for (j = i + 1; j != n; ++j) {
      g[i][j] = INT_MAX;
      g[j][i] = INT_MAX;
    }
  while (m--) {
    scanf("%d%d%d", &i, &j, &k);
    if (k < g[i][j])
      g[i][j] = k;
  }
  for (k = 0; k != n; ++k)
    for (i = 0; i != n; ++i)
      for (j = 0; j != n; ++j) {
        m = max(g[i][k], g[k][j]);
        if (m < g[i][j])
          g[i][j] = m;
      }
  while (q--) {
    scanf("%d%d", &i, &j);
    m = max(g[i][j], g[j][i]);
    printf("%d\n", m == INT_MAX ? -1 : m);
  }
  return 0;
}
