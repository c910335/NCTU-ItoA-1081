#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::sort;

struct M {
  int t, d;
};

int n, a, b, i, t;
M m[1000000];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n;
  n <<= 1;
  for (i = 0; i != n; ++i) {
    cin >> a >> b;
    m[i].t = a;
    m[i++].d = 1;
    m[i].t = b;
    m[i].d = -1;
  }
  a = b = 1;
  sort(m, m + n, [](M &x, M &y) -> bool {
    if (x.t == y.t)
      return x.d < y.d;
    return x.t < y.t;
  });
  for (i = 1; i != n; ++i) {
    a += m[i].d;
    if (b < a) {
      b = a;
      t = i;
    }
  }
  cout << m[t].t << ' ' << b;
  return 0;
}
