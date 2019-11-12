#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

int k, a[13], i, b[6];

void print() {
  cout << b[0];
  for (i = 1; i != 6; ++i)
    cout << ' ' << b[i];
  cout << endl;
}

void comb(int x, int y) {
  if (y == 6) {
    print();
    return;
  }
  if (x == k)
    return;
  int j;
  for (j = x; j != k; ++j) {
    b[y] = a[j];
    comb(j + 1, y + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
  for (;;) {
    cin >> k;
    if (k == 0)
      break;
    for (i = 0; i != k; ++i)
      cin >> a[i];
    comb(0, 0);
    cout << endl;
  }
  return 0;
}
