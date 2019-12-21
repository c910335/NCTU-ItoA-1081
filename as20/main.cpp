#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::fill;
using std::max;
using std::priority_queue;
using std::vector;

struct E {
  int t, k;
  E *n;
};

struct V {
  int i, k;

  bool operator < (const V &o) const {
    return k > o.k;
  }
};

int n, m, q, i, j, k, h[500][500], d[500][500];
bool p[500];
E *g[500], *t;
V c, v;
priority_queue<V> pq;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n >> m >> q;
  while (m--) {
    cin >> i >> j >> k;
    if (!h[i][j] || k < h[i][j])
      h[i][j] = k;
  }
  for (i = 0; i != n; ++i)
    for (j = 0; j != n; ++j)
      if (h[i][j]) {
        t = new E;
        t->n = g[i];
        t->t = j;
        t->k = h[i][j];
        g[i] = t;
      }
  while (q--) {
    cin >> i >> j;
    if (!d[i][j]) {
      fill(d[i], d[i] + n, INT_MAX);
      fill(p, p + n, false);
      d[i][i] = 0;
      c.i = i;
      c.k = 0;
      pq.push(c);
      while (!pq.empty()) {
        c = pq.top();
        pq.pop();
        if (p[c.i])
          continue;
        p[c.i] = true;
        for (t = g[c.i]; t; t = t->n)
          if (!p[t->t]) {
            m = max(d[i][c.i], t->k);
            if (m < d[i][t->t]) {
              d[i][t->t] = m;
              v.i = t->t;
              v.k = m;
              pq.push(v);
            }
          }
      }
    }
    if (!d[j][i]) {
      fill(d[j], d[j] + n, INT_MAX);
      fill(p, p + n, false);
      d[j][j] = 0;
      c.i = j;
      c.k = 0;
      pq.push(c);
      while (!pq.empty()) {
        c = pq.top();
        pq.pop();
        if (p[c.i])
          continue;
        p[c.i] = true;
        for (t = g[c.i]; t; t = t->n)
          if (!p[t->t]) {
            m = max(d[j][c.i], t->k);
            if (m < d[j][t->t]) {
              d[j][t->t] = m;
              v.i = t->t;
              v.k = m;
              pq.push(v);
            }
          }
      }
    }
    m = max(d[i][j], d[j][i]);
    cout << (m == INT_MAX ? -1 : m) << endl;
  }
  return 0;
}
