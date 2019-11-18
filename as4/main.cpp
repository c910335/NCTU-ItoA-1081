#include <iostream>
#include <climits>
#define SIZE 300000
#define max(x, y) x > y ? x : y

using std::cin;
using std::cout;
using std::endl;

int n, m, a[SIZE], i, st[SIZE << 2], j, k;

int build(int l, int r, int i) {
  if (l >= r - 1)
    return st[i] = a[l];
  int m = (l + r) >> 1, x = build(l, m, (i << 1) + 1), y = build(m, r, (i << 1) + 2);
  return st[i] = max(x, y);
}

void update() {
  int l = 0, r = n, i = 0, m;
  while (l < r - 1) {
    m = (l + r) >> 1;
    i <<= 1;
    if (m > j) {
      r = m;
      i++;
    } else {
      l = m;
      i += 2;
    }
  }
  st[i] = k;
  while (i > 0) {
    i = (i - 1) >> 1;
    st[i] = max(st[(i << 1) + 1], st[(i << 1) + 2]);
  }
}

int query(int l, int r, int i) {
  if (j <= l && r <= k)
    return st[i];
  int m = (l + r) >> 1, x = INT_MIN, y;
  if (j < m && (y = query(l, m, (i << 1) + 1)) && y > x)
    x = y;
  if (m < k && (y = query(m, r, (i << 1) + 2)) && y > x)
    x = y;
  return x;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n >> m;
  for (i = 0; i != n; ++i)
    cin >> a[i];
  build(0, n, 0);
  while (m--) {
    cin >> i >> j >> k;
    if (i == 1)
      update();
    else {
      k++;
      cout << query(0, n, 0) << endl;
    }
  }
  return 0;
}
