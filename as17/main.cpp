#include <algorithm>
#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::fill;
using std::stack;

struct E {
  int t, l;
  E *n;
};

int n, i, a, b, l;
long long d[100000], m, c;
E *g[100000], *t;
stack<int> s;

void add() {
  t = new E;
  t->t = a;
  t->l = l;
  t->n = g[b];
  g[b] = t;
  t = new E;
  t->t = b;
  t->l = l;
  t->n = g[a];
  g[a] = t;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n;
  for (i = 1; i != n; ++i) {
    cin >> a >> b >> l;
    a--;
    b--;
    c += l;
    add();
  }
  s.push(0);
  d[0] = 1;
  while (!s.empty()) {
    a = s.top();
    s.pop();
    for (t = g[a]; t; t = t->n)
      if (!d[t->t]) {
        d[t->t] = d[a] + t->l;
        if (d[t->t] > d[b])
          b = t->t;
        s.push(t->t);
      }
  }
  fill(d, d + n, 0);
  s.push(b);
  m = d[b] = 1;
  while (!s.empty()) {
    a = s.top();
    s.pop();
    for (t = g[a]; t; t = t->n)
      if (!d[t->t]) {
        d[t->t] = d[a] + t->l;
        if (d[t->t] > m)
          m = d[t->t];
        s.push(t->t);
      }
  }
  cout << c * 2 - m + 1;
  return 0;
}
