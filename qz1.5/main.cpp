#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::sort;

struct C {
  int u, v, i;
};

int n, i, a[1500001], j, u, v;
C c[1500000];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n;
  for (i = 0; i != n; ++i) {
    cin >> c[i].u >> c[i].v;
    c[i].i = i;
  }
  sort(c, c + n, [](const C &a, const C &b) -> bool {
      if (a.u == b.u)
        return a.v < b.v;
      return a.u < b.u;
    });
  i = n - 1;
  a[c[i].i] = 1;
  u = c[i].u;
  v = c[i].v;
  while (i--)
    if (c[i].v > v || (c[i].v == v && c[i].u == u)) {
      u = c[i].u;
      v = c[i].v;
      a[c[i].i] = 1;
    }
  for (i = 0; i != n; ++i)
    if (a[i])
      cout << i + 1 << ' ';
  return 0;
}
