#include <iostream>
#include <climits>
#define SIZE 2000000

using std::cin;
using std::cout;
using std::endl;

struct N {
  int m, s;
};

int n, m, i, j;
N s[SIZE * 2], a, t;

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

void as(N *p, N *c) {
  t.m = p->m;
  t.s = p->s;
  up(p, c, &t);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n >> m;
  for (i = n; i != n + n; ++i) {
    cin >> s[i].m;
    s[i].s = INT_MAX;
  }
  for (i = n - 1; i != 0; --i)
    up(s + i, s + (i << 1), s + (i << 1) + 1);
  while (m--) {
    cin >> i >> j;
    a.m = a.s = INT_MAX;
    i += n;
    j += n + 1;
    while (i < j - 1) {
      if (i & 1) {
        as(&a, s + i);
        i++;
      }
      if (j & 1) {
        j--;
        as(&a, s + j);
      }
      i >>= 1;
      j >>= 1;
    }
    if (i < j)
      as(&a, s + i);
    cout << a.s << endl;
  }
  return 0;
}
