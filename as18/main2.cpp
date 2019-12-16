#include <climits>
#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::priority_queue;

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

int n, m, w, i, j, k, l = -1, a, p[100000], d[100000];
E *g[100000], *t;
V c, v;
priority_queue<V> q;

void add() {
  t = new E();
  t->t = i;
  t->k = k;
  t->n = g[j];
  g[j] = t;
  t = new E();
  t->t = j;
  t->k = k;
  t->n = g[i];
  g[i] = t;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n >> m >> w;
  while (m--) {
    cin >> i >> j >> k;
    if (k >= w)
      continue;
    add();
  }
  for (i = 0; i != n; ++i)
    d[i] = INT_MAX;
  for (i = 0; i != n; ++i) {
    if (p[i])
      continue;
    l++;
    v.i = i;
    v.k = 0;
    d[i] = 0;
    q.push(v);
    while (!q.empty()) {
      c = q.top();
      q.pop();
      if (p[c.i])
        continue;
      p[c.i] = 1;
      a += c.k;
      for (t = g[c.i]; t; t = t->n) {
        if (t->k < d[t->t] && !p[t->t]) {
          d[t->t] = t->k;
          v.i = t->t;
          v.k = t->k;
          q.push(v);
        }
      }
    }
  }
  cout << a + l * w;
  return 0;
}
