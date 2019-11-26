#include <stdio.h>

int n, a, m;

int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  while (--n) {
    scanf("%d", &a);
    if (a > m)
      m = a;
  }
  printf("%d", m);
  return 0;
}
