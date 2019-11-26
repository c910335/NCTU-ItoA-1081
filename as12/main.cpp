#include <algorithm>
#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::priority_queue;
using std::sort;

struct A {
  int d, t;
};

int n, i, c;
long long t;
A a[1000000];
priority_queue<int> q;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n;
  for (i = 0; i != n; ++i)
    cin >> a[i].d >> a[i].t;
  sort(a, a + n, [](const A &a, const A &b) -> bool { return a.d < b.d; });
  c = n;
  for (i = 0; i != n; ++i) {
    t += a[i].t;
    q.push(a[i].t);
    if (t > a[i].d) {
      t -= q.top();
      q.pop();
      c--;
    }
  }
  cout << c;
  return 0;
}
