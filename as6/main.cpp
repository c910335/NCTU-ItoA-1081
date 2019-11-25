#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::sort;

struct Point {
  int x, y, i;
};

int n, r[300000], i, j, t, b[300001];
Point a[300000];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL); 
  cin >> n;
  for (i = 0; i != n; ++i) {
    cin >> a[i].x >> a[i].y;
    a[i].i = i;
  }

  sort(a, a + n, [](Point a, Point b) -> bool {
    if (a.x == b.x)
      return a.y < b.y;
    return a.x < b.x;
  });
  t = a[0].x;
  a[0].x = j = 1;
  for (i = 1; i != n; ++i) {
    if (a[i].x != t) {
      t = a[i].x;
      j++;
    }
    a[i].x = j;
  }
  sort(a, a + n, [](Point a, Point b) -> bool {
    if (a.y == b.y)
      return a.x < b.x;
    return a.y < b.y;
  });

  for (i = 0; i != n; ++i) {
    t = 0;
    for (j = a[i].x; j > 0; j &= j - 1)
      t += b[j];
    r[a[i].i] = t;
    for (j = a[i].x; j <= n; j += j & (-j))
      b[j]++;
  }
  
  cout << r[0];
  for (i = 1; i != n; ++i)
    cout << ' ' << r[i];
  cout << endl;
  return 0;
}
