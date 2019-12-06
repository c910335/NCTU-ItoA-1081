#include <stdio.h>
#include <stdlib.h>
#define ht_size 15485867

typedef struct e {
  int n;
  struct e *t;
} e;

int n, a[2500], i, j;
e *h[ht_size], *t;

int check(int n) {
  for (t = h[(n % ht_size + ht_size) % ht_size]; t; t = t->t)
    if (t->n == n)
      return 1;
  return 0;
}

void add(int n) {
  t = (e*) malloc(sizeof(e));
  t->n = n;
  t->t = h[(n % ht_size + ht_size) % ht_size];
  h[(n % ht_size + ht_size) % ht_size] = t;
}

int main() {
  scanf("%d", &n);
  for (i = 0; i != n; ++i)
    scanf("%d", a + i);
  for (i = 1; i < n - 2; ++i) {
    for (j = 0; j < i; ++j)
      add(a[i] + a[j]);
    for (j = i + 2; j < n; ++j) {
      if (check(-a[i + 1] - a[j])) {
        putchar('1');
        return 0;
      }
    }
  }
  putchar('0');
  return 0;
}
