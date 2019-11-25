#include <stdio.h>
#define SIZE 500000
#define MOD 524287
#define swap(x, y) t=x;x=y;y=t

int n, a[SIZE], i, j, t;
long long c;

void heapify(int i) {
  j = (i << 1) + 1;
  while (j < n) {
    if (j + 1 < n && a[j + 1] < a[j])
      j++;
    if (a[i] < a[j])
      break;
    swap(a[i], a[j]);
    i = j;
    j = (j << 1) + 1;
  }
}

void make_heap() {
  for (i = n / 2; i >= 0; --i)
    heapify(i);
}

int main() {
  scanf("%d", &n);
  for (i = 0; i != n; ++i)
    scanf("%d", a + i);
  make_heap();
  while (n-- > 1) {
    swap(a[0], a[n]);
    heapify(0);
    a[0] += a[n];
    c += a[0];
    heapify(0);
  }
  printf("%lld", c % MOD);
  return 0;
}
