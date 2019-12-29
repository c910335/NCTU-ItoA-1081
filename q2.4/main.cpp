#include <climits>
#include <iostream>
#include <queue>
#define MAX_V 500000

using std::cin;
using std::cout;
using std::fill;
using std::priority_queue;

struct V {
  int v, w;

  bool operator < (const V &o) const {
    return w > o.w;
  }
};

struct E {
  int t, w;
  E *n;

  E (int t, int w, E *n) : t(t), w(w), n(n) {}
};

int n, m, i, w[MAX_V], a, b, c;
long long d[MAX_V], s;
E *g[MAX_V], *t;
priority_queue<V> q;
V u;
bool v[MAX_V];

int main() {
  cin >> n >> m;
  for (; i != n; ++i)
    cin >> w[i];
  while (m--) {
    cin >> a >> b >> c;
    t = new E(a, c + w[a], g[b]);
    g[b] = t;
    t = new E(b, c + w[b], g[a]);
    g[a] = t;
  }
  fill(d + 1, d + n, LLONG_MAX);
  d[0] = w[0];
  q.push(u);
  while (!q.empty()) {
    c = q.top().v;
    q.pop();
    if (v[c])
      continue;
    v[c] = true;
    s += d[c];
    for (t = g[c]; t; t = t->n)
      if (d[c] + t->w < d[t->t]) {
        d[t->t] = d[c] + t->w;
        u.v = t->t;
        u.w = d[t->t];
        q.push(u);
      }
  }
  cout << s - d[0];
  return 0;
}
