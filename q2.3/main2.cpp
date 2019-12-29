#include <algorithm>
#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::fill;
using std::priority_queue;

struct E {
  int t, w;
  E *n;
  E (int t, int w, E *n) : t(t), w(w), n(n) {}
};

struct V {
  int i, w;

  bool operator < (const V &o) const {
    return w < o.w;
  }
};

int n, m, a, b, c, d[500000];
E *g[500000], *t;
priority_queue<V> q;
V v;
bool p[500000];
long long s;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n >> m;
  while (m--) {
    cin >> a >> b >> c;
    t = new E(a, c, g[b]);
    g[b] = t;
    t = new E(b, c, g[a]);
    g[a] = t;
  }
  q.push(v);
  while (!q.empty()) {
    c = q.top().i;
    q.pop();
    if (p[c])
      continue;
    p[c] = true;
    s += d[c];
    for (t = g[c]; t; t = t->n)
      if (t->w > d[t->t] && !p[t->t]) {
        d[t->t] = t->w;
        v.i = t->t;
        v.w = t->w;
        q.push(v);
      }
  }
  cout << s;
  return 0;
}
