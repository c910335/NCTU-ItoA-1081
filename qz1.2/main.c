#include <stdio.h>
#include <limits.h>
#define SIZE 2000000

typedef struct {
  int m, s;
} N;

int n, m, i, j, k, a[SIZE];
N s[SIZE << 2], t, tt;

void up(N *p, N *l, N *r) {
  if (l->m <= r->m) {
    p->m = l->m;
    if (r->m <= l->s)
      p->s = r->m;
    else
      p->s = l->s;
  } else {
    p->m = r->m;
    if (l->m <= r->s)
      p->s = l->m;
    else
      p->s = r->s;
  }
}

void b(int l, int r, int i) {
  if (l >= r - 1) {
    s[i].m = a[l];
    s[i].s = INT_MAX;
    return;
  }
  int m = (l + r) >> 1, j = (i << 1) + 1, k = (i << 1) + 2;
  b(l, m, j);
  b(m, r, k);
  up(s + i, s + j, s + k);
}

void as(N *p, N *c) {
  tt.m = p->m;
  tt.s = p->s;
  up(p, c, &tt);
}

void q(int l, int r, int i) {
  if (j <= l && r <= k) {
    as(&t, s + i);
    return;
  }
  int m = (l + r) >> 1;
  if (j < m)
    q(l, m, (i << 1) + 1);
  if (m < k)
    q(m, r, (i << 1) + 2);
}

int main() {
  scanf("%d%d", &n, &m);
  for (i = 0; i != n; ++i)
    scanf("%d", a + i);
  b(0, n, 0);
  while (m--) {
    scanf("%d%d", &j, &k);
    k++;
    t.m = t.s = INT_MAX;
    q(0, n, 0);
    printf("%d\n", t.s);
  }
  return 0;
}
