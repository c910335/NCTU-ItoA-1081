#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int i, x, y;
} point;

int cmp(const void * a, const void * b) {
  if ((*(point*)a).x == (*(point*)b).x) {
    if ((*(point*)a).y < (*(point*)b).y)
      return -1;
    if ((*(point*)a).y == (*(point*)b).y)
      return 0;
    return 1;
  }
  if ((*(point*)a).x < (*(point*)b).x)
    return -1;
  return 1;
}

int n, ranks[300000];
point ps[300000];

void find_ranks(int first, int last) {
  if (last - first <= 1)
    return;

  int mid = (first + last) / 2;
  find_ranks(first, mid);
  find_ranks(mid, last);

  int i, j = 0, k = mid, size = mid - first;
  point *tps = (point*) malloc(size * sizeof(point));
  for (i = 0; i != size; ++i)
    tps[i] = ps[i + first];

  for(i = first;; ++i) {
    if (tps[j].y <= ps[k].y) {
      ps[i] = tps[j++];
      if (j == size) {
        for (; k != last; ++k)
          ranks[ps[k].i] += j;
        break;
      }
    } else {
      ps[i] = ps[k];
      ranks[ps[k].i] += j;
      k++;
      if (k == last) {
        for (++i; i != last; ++i, ++j)
          ps[i] = tps[j];
        break;
      }
    }
  }
  free(tps);
}

int main(int argc, char *args[]) {
  scanf("%d", &n);
  int i;
  for (i = 0; i != n; ++i) {
    scanf("%d%d", &ps[i].x, &ps[i].y);
    ps[i].i = i;
    ranks[i] = 0;
  }

  qsort(ps, n, sizeof(point), cmp);

  find_ranks(0, n);

  printf("%d", ranks[0]);
  for (i = 1; i != n; ++i)
    printf(" %d", ranks[i]);
  puts("");
}
