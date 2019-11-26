#include <iostream>

using std::cin;
using std::cout;

int n, i, a[300], s, m, j, d[150001];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n;
  for (i = 0; i != n; ++i) {
    cin >> a[i];
    s += a[i];
  }
  m = s >> 1;
  for (i = 0; i != n; ++i)
    for (j = m; j >= a[i]; --j)
      if (d[j] < d[j - a[i]] + a[i])
        d[j] = d[j - a[i]] + a[i];
  cout << s - (d[m] << 1);
  return 0;
}
