#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;
using std::sort;

struct L {
  char l;
  int c;
};

char s[1001];
int i;
L c[26];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s;
  for (i = 0; i != 26; ++i) {
    c[i].l = 'A' + i;
    c[i].c = 0;
  }
  for (i = 0; s[i] != '\0'; ++i)
    c[s[i] - 'A'].c++;
  sort(
    c,
    c + 26,
    [] (L a, L b) -> bool {
      if (a.c == b.c)
        return a.l < b.l;
      return a.c > b.c;
    }
  );
  for (i = 0; i != 26; ++i)
    if (c[i].c)
      cout << (int) c[i].l << ' ' << c[i].c << endl;
  return 0;
}
