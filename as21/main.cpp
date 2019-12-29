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

int n, m, a, b;
E *g[300], *u, *v, *p[300];
bool f[300];
queue<int> q;

bool bfs() {
  fill(f + 1, f + n, false);
  while (!q.empty())
    q.pop();
  q.push(0);
  while (!q.empty()) {
    b = q.front();
    q.pop();
    for (u = g[b]; u; u = u->n)
      if (!f[u->t] && u->c) {
        p[u->t] = u->p;
        if (u->t == n)
          return true;
        f[u->t] = true;
        q.push(u->t);
      }
  }
  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n >> m;
  while (m--) {
    cin >> a >> b;
    u = new E(1, b, g[a]);
    g[a] = u;
    v = new E(1, a, g[b]);
    g[b] = v;
    u->p = v;
    v->p = u;
  }
  a = 0;
  n--;
  f[0] = true;
  while (bfs()) {
    for (u = p[n]; u; u = p[u->t]) {
      u->c++;
      u->p->c--;
    }
    a++;
  }
  cout << a;
  return 0;
}
