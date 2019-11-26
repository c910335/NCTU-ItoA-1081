#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::sort;

struct A {
  int s, t, d;
};

int n, i, j, d[30001], s;
A a[20000];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n;
  for (i = 0; i != n; ++i)
    cin >> a[i].s >> a[i].d >> a[i].t;
  sort(a, a + n, [](const A &x, const A &y) -> bool { return x.d < y.d; });
  s = 0;
  for (i = 0; i != n; ++i)
    for (j = a[i].d; j >= a[i].t; j--)
      if (d[j] < d[j - a[i].t] + a[i].s) {
        d[j] = d[j - a[i].t] + a[i].s;
        if (s < d[j])
          s = d[j];
      }
  cout << s;
  return 0;
}
