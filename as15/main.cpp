#include <algorithm>
#include <iostream>
#define SIZE 300000

using std::cin;
using std::cout;
using std::sort;

struct A {
  int s, d;
};

int n, i, j, k, m, t, p[SIZE + 1];
long long s;
A a[SIZE];

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
  cin >> n;
  for (i = 0; i != n; ++i) {
    cin >> a[i].s >> a[i].d;
    p[i] = i;
  }
  m = n;
  sort(a, a + n, [](const A &x, const A &y) -> bool { return x.s > y.s; });
  for (i = 0; i != n; ++i)
    if (a[i].d >= m) {
      s += a[i].s;
      m--;
    } else if ((k = f(a[i].d))) {
      s += a[i].s;
      p[k] = f(k - 1);
    }
  cout << s;
  return 0;
}
