#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::sort;

struct E {
  int x, y, w;
};

int n, m, i, p[500000], r, t, x, y;
long long w;
E e[800000];

int f(int x) {
  for (r = p[x]; r != p[r]; r = p[r]);
  while (x != r) {
    t = p[x];
    p[x] = r;
    x = t;
  }
  return r;
}

int main() {
  cin >> n >> m;
  for (i = 1; i != n; ++i)
    p[i] = i;
  for (i = 0; i != m; ++i)
    cin >> e[i].x >> e[i].y >> e[i].w;
  sort(e, e + m, [](E &x, E &y) -> bool { return x.w < y.w; });
  while (i--) {
    x = f(e[i].x);
    y = f(e[i].y);
    if (x != y) {
      p[x] = y;
      w += e[i].w;
    }
  }
  cout << w;
  return 0;
}
