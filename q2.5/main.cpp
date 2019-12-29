#include <algorithm>
#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::fill;
using std::queue;

struct E {
  int c, t;
  E *n, *p;

  E(int c, int t, E *n) : c(c), t(t), n(n) {}
};

int n, m, r, i, a, b;
bool f[2002];
E *g[2002], *u, *v, *p[2002];
queue<int> q;

void add(int f, int t) {
  u = new E(0, f, g[t]);
  v = new E(1, t, g[f]);
  u->p = v;
  v->p = u;
  g[t] = u;
  g[f] = v;
}

bool bfs() {
  fill(f + 1, f + m, false);
  while (!q.empty())
    q.pop();
  q.push(0);
  while (!q.empty()) {
    b = q.front();
    q.pop();
    for (u = g[b]; u; u = u->n)
      if (!f[u->t] && u->c) {
        p[u->t] = u->p;
        f[u->t] = true;
        if (u->t == 1)
          return true;
        q.push(u->t);
      }
  }
  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n >> m >> r;
  n += 2;
  for (i = 2; i != n; ++i)
    add(0, i);
  m += n;
  for (;i != m; ++i)
    add(i, 1);
  while (r--) {
    cin >> a >> b;
    add(a + 2, b + n);
  }
  a = 0;
  f[0] = true;
  while (bfs()) {
    for (u = p[1]; u; u = p[u->t]) {
      u->c++;
      u->p->c--;
    }
    a++;
  }
  cout << a;
  return 0;
}
