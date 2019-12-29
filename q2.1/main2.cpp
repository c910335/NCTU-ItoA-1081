#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::stack;

struct E {
  int t;
  E *n;

  E(int t, E *n) : t(t), n(n) {}
};

int n, i, a, b, c, d[100000];
E *g[100000], *t, *u;
stack<int> s;
bool m[100000];

int main() {
  scanf("%d", &n);
  for (i = 1; i != n; ++i) {
    scanf("%d%d", &a, &b);
    t = new E(a, g[b]);
    g[b] = t;
    t = new E(b, g[a]);
    g[a] = t;
    d[a]++;
    d[b]++;
  }
  a = 0;
  for (i = 0; i != n; ++i)
    if (d[i] == 1)
      s.push(i);
  while (!s.empty()) {
    c = s.top();
    s.pop();
    if (m[c])
      continue;
    for (t = g[c]; t; t = t->n)
      if (!m[t->t]) {
        m[c] = m[t->t] = 1;
        a++;
        for (u = g[t->t]; u; u = u->n) {
          d[u->t]--;
          if (!m[u->t] && d[u->t] == 1)
            s.push(u->t);
        }
        break;
      }
  }
  printf("%d", a);
  return 0;
}
