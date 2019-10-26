#include <stdio.h>

int n, s, a;

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &a);
    s += a;
  }
  printf("%d", s);
  return 0;
}
