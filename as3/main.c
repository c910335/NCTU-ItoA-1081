#include <stdio.h>
#define SIZE 10000000
#define MOD 524287

int n, a[SIZE], t[SIZE / 2], i, ti, f;
long long c;

void count(int *l, int *r) {
  if (r - l <= 1)
    return;
  int *m = l + (r - l) / 2;
  count(l, m);
  count(m, r);
  int i, j = 0, ls = m - l, rs = r - m;
  for (i = 0; i != ls; ++i)
    *(t + i) = *(l + i);
  for (i = 0; i != ls && j != rs; l++) {
    if (*(t + i) <= *(m + j)) {
      *l = *(t + i);
      i++;
      c += j;
    } else {
      *l = *(m + j);
      j++;
    }
  }
  for (; i != ls; i++, l++) {
    *l = *(t + i);
    c += j;
  }
}

int main() {
  scanf("%d", &n);
  for (i = 0; i != n; ++i)
    scanf("%d", a + i);
  count(a, a + n);
  printf("%lld", c % MOD);
  return 0;
}
