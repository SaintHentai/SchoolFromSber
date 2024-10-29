#include <stdio.h>

int main(void) {
  int in, cur;

  scanf("%d", &in);

  int head = in / 100;
  int mid = (in / 10) % 10;
  int tail = in % 10;

  if (head < mid)
    cur = mid;
  else
    cur = head;
  if (cur < tail)
    cur = tail;

  printf("%d", cur);
  return 0;
}
