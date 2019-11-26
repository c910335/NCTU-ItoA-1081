#include <stdio.h>
#define SIZE 3000000

int n, a[SIZE], t[SIZE], i, j, k, l, m;
long long c;

int main() {
  scanf("%d", &n);
  for (i = 0; i != n; ++i)
    scanf("%d", a + i);
  for (i = 1; i < n; i <<= 1)
    for (j = 0; j < n;) {
      l = j + i;
      if (l < n) {
        for (k = 0; k != i; ++k)
          t[k] = a[j + k];
        m = l + i;
        if (m > n)
          m = n;
        for (k = 0;;) {
          if (t[k] <= a[l]) {
            a[j++] = t[k++];
            if (k == i)
              break;
          } else {
            a[j++] = a[l++];
            c += i - k;
            if (l == m)
              break;
          }
        }
        while (k != i)
          a[j++] = t[k++];
        j += m - l;
      } else
        break;
    }
  printf("%lld", c);
  return 0;
}
