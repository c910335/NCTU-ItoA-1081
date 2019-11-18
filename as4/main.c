#include <stdio.h>
#include <limits.h>
#define SIZE 300000
#define max(x, y) x > y ? x : y

int n, m, i, st[SIZE << 1], j, k, a;

int main() {
  scanf("%d%d", &n, &m);
  for (i = n; i != n << 1; ++i)
    scanf("%d", st + i);
  for (i = n - 1; i != 0; --i)
    st[i] = max(st[i << 1], st[(i << 1) + 1]);
  while (m--) {
    scanf("%d%d%d", &i, &j, &k);
    j += n;
    if (i == 1) {
      st[j] = k;
      while (j >>= 1)
        st[j] = max(st[j << 1], st[(j << 1) + 1]);
    } else {
      k += n + 1;
      a = INT_MIN;
      while (j < k) {
        if (j & 1) {
          if (a < st[j])
            a = st[j];
          j++;
        }
        if (k & 1) {
          k--;
          if (a < st[k])
            a = st[k];
        }
        j >>= 1;
        k >>= 1;
      }
      printf("%d\n", a);
    }
  }
  return 0;
}
