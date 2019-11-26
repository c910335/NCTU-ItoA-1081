#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::sort;

class P {
  public:
    int s, i, j;
};

int n, a[2500], i, j, k;
P d[3123750];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n;
  for (i = 0; i != n; ++i)
    cin >> a[i];
  for (i = 0, k = 0; i < n - 1; ++i)
    for (j = i + 1; j < n; ++j) {
      d[k].s = a[i] + a[j];
      d[k].i = i;
      d[k].j = j;
      k++;
    }
  sort(d, d + k, [](P a, P b) -> bool { return a.s < b.s; });
  i = 0;
  j = k - 1;
  while (i < j) {
    if (d[i].s + d[j].s == 0 && d[i].i != d[j].i && d[i].i != d[j].j && d[i].j != d[j].i && d[i].j != d[j].j) {
      cout << '1';
      return 0;
    }
    if (d[i].s + d[j].s < 0)
      i++;
    else
      j--;
  }
  cout << '0';
  return 0;
}
