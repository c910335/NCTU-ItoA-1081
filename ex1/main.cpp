#include <iostream>

using std::cin;
using std::cout;

int n, s, a;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  cin >> n;
  while (n--) {
    cin >> a;
    s += a;
  }
  cout << s;
  return 0;
}
