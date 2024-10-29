#include <stdio.h>

int main(void) {
  int in, cur, res = 1;

  scanf("%d", &in);
  if (in < 0) {
    in = in - 2 * in;
  }

  while (in != 0) {
    cur = in % 10;
    if (cur % 2 != 0)
      res = res * cur;
    in = in / 10;
  }
  if (res == 1)
    res = 0;
  printf("%d", res);
  return 0;
}
