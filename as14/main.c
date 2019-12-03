#include <stdio.h>
#define swap(x,y) t=x;x=y;y=t

int n, i, j, k;
long long w[100000], t;

void down(int c) {
  j = c;
  k = (c << 1) + 1;
  while (k < n) {
    if (k + 1 < n && w[k + 1] < w[k])
      k++;
    if (w[j] < w[k])
      break;
    swap(w[j], w[k]);
    j = k;
    k = (k << 1) + 1;
  }
}

int main() {
  scanf("%d", &n);
  for (i = 0; i != n; ++i)
    scanf("%lld", w + i);
  for (i = n >> 1; i >= 0; --i)
    down(i);
  while (n-- > 1) {
    swap(w[0], w[n]);
    down(0);
    w[0] = (w[0] + w[n]) << 1;
    down(0);
  }
  printf("%lld", w[0]);
  return 0;
}
