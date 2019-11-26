#include <stdio.h>
#include <stdlib.h>
#define ht_size 15485867

typedef struct e {
  int n, i, j;
  struct e *t;
} e;

int n, a[2500], i, j;
e *h[ht_size], *t;

int check(int n) {
  t = h[(n % ht_size + ht_size) % ht_size];
  while (t != NULL) {
    if (t->n == n && i != t->i && i != t->j && j != t->j)
      return 1;
    t = t->t;
  }
  return 0;
}

void add(int n) {
  t = (e*) malloc(sizeof(e));
  t->n = n;
  t->i = i;
  t->j = j;
  t->t = h[(n % ht_size + ht_size) % ht_size];
  h[(n % ht_size + ht_size) % ht_size] = t;
}

int main() {
  scanf("%d", &n);
  for (i = 0; i != n; ++i)
    scanf("%d", a + i);
  for (i = 0; i != n; ++i)
    for (j = i + 1; j < n; ++j) {
      if (check(-a[i] - a[j])) {
        putchar('1');
        return 0;
      }
      add(a[i] + a[j]);
    }
  putchar('0');
  return 0;
}
