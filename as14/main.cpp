#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::greater;
using std::priority_queue;
using std::vector;

int n, i, j, k;
long long w, t;
priority_queue<long long, vector<long long>, greater<long long> > q;

int main() {
  scanf("%d", &n);
  for (i = 0; i != n; ++i) {
    scanf("%lld", &w);
    q.push(w);
  }
  while (n-- > 1) {
    w = q.top();
    q.pop();
    t = q.top();
    q.pop();
    w = (w + t) << 1;
    q.push(w);
  }
  printf("%lld", q.top());
  return 0;
}
