#include <stdio.h>

const int MOD = 524287;
int n, a, b, c, d, i;
int s[2000000];

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    for (i = 0; c; i++) {
      if (c == a && d == b)
        break;
      if (c < d) {
        d -= c;
        s[i] = 0;
      } else {
        c -= d;
        s[i] = 1;
      }
    }
    if (c) {
      a = 1;
      while (i--)
        a = (a * 2 + s[i]) % MOD;
      printf("%d\n", a);
    } else
      puts("-1");
  }
  return 0;
}
