#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char l;
  int c;
} L;

int cmp(const void *x, const void *y) {
  if (((L*) x)->c == ((L*) y)->c)
    return ((L*) x)->l - ((L*) y)->l;
  return ((L*) y)->c - ((L*) x)->c;
}

char s[1001];
int i;
L c[26];

int main() {
  scanf("%s", s);
  for (i = 0; i != 26; ++i) {
    c[i].l = 'A' + i;
    c[i].c = 0;
  }
  for (i = 0; s[i] != '\0'; ++i)
    c[s[i] - 'A'].c++;
  qsort(c, 26, sizeof(L), cmp);
  for (i = 0; i != 26; ++i) {
    if (c[i].c)
      printf("%d %d\n", c[i].l, c[i].c);
  }
  return 0;
}
