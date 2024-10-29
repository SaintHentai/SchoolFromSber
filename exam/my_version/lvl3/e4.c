#include <stdio.h>
int main(void) {
  int a, b, c, result = 0;
  scanf("%d %d %d", &a, &b, &c);

  result = (a + b) - c > 0;

  printf("%d", result);
  return 0;
}
