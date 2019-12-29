#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::fill;
using std::min;
using std::queue;

struct E {
  int c, t;
  E *n, *p;

  E(int c, int t, E *n) : c(c), t(t), n(n) {}
};

int n, m, i, c, s, j, f[262], af;
E *g[262], *u, *v, *p[262];
queue<int> q;

void add(int f, int t, int c) {
  u = new E(0, f, g[t]);
  v = new E(c, t, g[f]);
  u->p = v;
  v->p = u;
  g[t] = u;
  g[f] = v;
}

int bfs() {
  fill(f + 1, f + n, 0);
  while (!q.empty())
    q.pop();
  q.push(0);
  while (!q.empty()) {
    c = q.front();
    q.pop();
    for (u = g[c]; u; u = u->n)
      if (!f[u->t] && u->c) {
        p[u->t] = u->p;
        f[u->t] = min(f[c], u->c);
        if (u->t == 1)
          return f[1];
        q.push(u->t);
      }
  }
  return 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n >> m;
  n += 2;
  for (i = 2; i != n; ++i) {
    cin >> c;
    s += c;
    add(i, 1, c);
  }
  for (; i != n + m; ++i) {
    cin >> c;
    add(0, i, c);
  }
  for (i = 2; i != n; ++i) {
    cin >> c;
    while (c--) {
      cin >> j;
      add(j + n, i, INT_MAX);
    }
  }
  n += m;
  f[0] = INT_MAX;
  while ((af = bfs())) {
    for (u = p[1]; u; u = p[u->t]) {
      u->c += af;
      u->p->c -= af;
    }
    s -= af;
  }
  cout << s;
  return 0;
}
