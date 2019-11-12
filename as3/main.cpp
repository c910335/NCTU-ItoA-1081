#include <iostream>
#include <algorithm>
#define SIZE 10000000
#define MOD 524287

using std::cin;
using std::cout;
using std::ios_base;
using std::sort;

struct P {
  int x, y;
};

int n, i, j, t, b[SIZE + 1];
P p[SIZE];
long long c;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (i = 0; i != n; ++i) {
    cin >> p[i].x;
    p[i].y = i;
  }
  sort(p, p + n, [](P &a, P &b) -> bool {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
  });
  for (i = 0; i != n; ++i)
    p[i].x = i + 1;
  sort(p, p + n, [](P &a, P &b) -> bool {
    return a.y < b.y;
  });
  c = 0;
  for (i = 0; i != n; ++i) {
    t = 0;
    for (j = p[i].x; j > 0; j &= j - 1)
      t += b[j];
    c += i - t;
    for (j = p[i].x; j <= n; j += j & (-j))
      b[j]++;
  }
  cout << c % MOD;
  return 0;
}
