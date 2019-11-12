#include <stdio.h>

int k, a[13], i, b[6];

void print() {
  printf("%d", b[0]);
  for (i = 1; i != 6; ++i)
    printf(" %d", b[i]);
  puts("");
}

void comb(int x, int y) {
  if (y == 6) {
    print();
    return;
  }
  if (x == k)
    return;
  int j;
  for (j = x; j != k; ++j) {
    b[y] = a[j];
    comb(j + 1, y + 1);
  }
}

int main() {
  for (;;) {
    scanf("%d", &k);
    if (k == 0)
      break;
    for (i = 0; i != k; ++i)
      scanf("%d", a + i);
    comb(0, 0);
    puts("");
  }
  return 0;
}
