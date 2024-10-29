#include <stdio.h>
int main(void) {
  int x, rezero = 0;
  scanf("%d", &x);
  while (x != 0) {
    int last = x % 10;

    rezero = rezero * 10 + last;

    x = x / 10;
  }

  printf("%d", rezero);
  return 0;
}
