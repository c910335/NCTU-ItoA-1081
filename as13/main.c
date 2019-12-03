#include <stdio.h>

int n, a, i, c, f, l = 1;
long long s, m;

int main() {
  scanf("%d", &n);
  scanf("%d", &a);
  m = a;
  if (a >= 0)
    s = a;
  else
    c = 1;
  for (i = 2; i <= n; ++i) {
    scanf("%d", &a);
    s += a;
    if (s > m) {
      m = s;
      f = c;
      l = i;
    }
    if (s < 0) {
      s = 0;
      c = i;
    }
  }
  printf("%d %d", f, l);
  return 0;
}
