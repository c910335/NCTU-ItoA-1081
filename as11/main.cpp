#include <iostream>

using std::cin;
using std::cout;

int n, m, s, t, d[50001], i;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n >> m;
  while (n--) {
    cin >> s >> t;
    for (i = m; i >= t; --i)
      if (d[i - t] + s > d[i])
        d[i] = d[i - t] + s;
  }
  cout << d[m];
  return 0;
}
