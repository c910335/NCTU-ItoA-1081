#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#define INF LLONG_MAX >> 4

using std::cin;
using std::cout;
using std::fill;
using std::priority_queue;

struct E {
  int t, k;
  E *n;
};

struct V {
  int i;
  long long k;

  bool operator < (const V &o) const {
    return k > o.k;
  }
};

int n, m, i, j, k;
long long d[2001], a;
bool p[2001];
E *g[2001], *h[2001], *t;
V c, v;
priority_queue<V> q;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n >> m;
  while (m--) {
    cin >> i >> j >> k;
    t = new E;
    t->n = g[i];
    t->t = j;
    t->k = k;
    g[i] = t;
    t = new E;
    t->n = h[j];
    t->t = i;
    t->k = k;
    h[j] = t;
  }
  fill(d + 1, d + n + 1, INF);
  q.push(c);
  while (!q.empty()) {
    c = q.top();
    q.pop();
    if (p[c.i])
      continue;
    p[c.i] = true;
    for (t = g[c.i]; t; t = t->n)
      if (!p[t->t] && d[c.i] + t->k < d[t->t]) {
        d[t->t] = d[c.i] + t->k;
        v.i = t->t;
        v.k = d[t->t];
        q.push(v);
      }
  }
  for (i = 1; i <= n; ++i)
    a += d[i];
  fill(d + 1, d + n + 1, INF);
  fill(p, p + n + 1, false);
  c.i = 0;
  c.k = 0;
  q.push(c);
  while (!q.empty()) {
    c = q.top();
    q.pop();
    if (p[c.i])
      continue;
    p[c.i] = true;
    for (t = h[c.i]; t; t = t->n)
      if (!p[t->t] && d[c.i] + t->k < d[t->t]) {
        d[t->t] = d[c.i] + t->k;
        v.i = t->t;
        v.k = d[t->t];
        q.push(v);
      }
  }
  for (i = 1; i <= n; ++i)
    a += d[i];
  cout << a;
  return 0;
}
