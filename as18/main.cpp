#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::sort;

struct E {
  int i, j, k;
};

int n, m, w, i, p[100000], j, t, l, c, a, b;
E e[300000];

int f(int x) {
  for (j = x; j != p[j]; j = p[j]);
  while (x != p[x]) {
    t = x;
    x = p[x];
    p[t] = j;
  }
  return j;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n >> m >> w;
  for (i = 0; i != m; ++i) {
    cin >> e[i].i >> e[i].j >> e[i].k;
    if (e[i].k >= w) {
      m--;
      i--;
    }
  }
  for (i = 1; i != n; ++i)
    p[i] = i;
  sort(e, e + m, [](const E x, const E y) -> bool { return x.k < y.k; });
  l = n - 1;
  for (i = 0; i != m; ++i) {
    a = f(e[i].i);
    b = f(e[i].j);
    if (a != b) {
      p[a] = b;
      c += e[i].k;
      l--;
      if (!l)
        break;
    }
  }
  cout << c + l * w;
  return 0;
}
