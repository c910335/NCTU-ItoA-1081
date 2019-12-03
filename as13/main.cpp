#include <iostream>

using std::cin;
using std::cout;

int n, a, i, c, f, l = 1;
long long s, m;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n >> a;
  m = a;
  if (a >= 0)
    s = a;
  else
    c = 1;
  for (i = 2; i != n; ++i) {
    cin >> a;
    s += a;
    if (s > m) {
      m = s;
      f = c;
      l = i;
    }
    if (s < 0) {
      s = 0;
      c = i;
    }
  }
  cout << f << ' ' << l;
  return 0;
}
