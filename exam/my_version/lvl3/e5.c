#include <stdio.h>
int main(void) {
  int a, b, c, result = 0;
  scanf("%d %d %d", &a, &b, &c);

  if (a < 0 || a > 1 || b < 0 || b > 1 || c < 0 || c > 1) {
    printf("n/a");
  }

  result = a && (b || c);

  printf("%d", result);
  return 0;
}
