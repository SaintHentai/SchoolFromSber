#include <math.h>
#include <stdio.h>

#define grad 57.29

int main(void) {
  double x;
  scanf("%lf", &x);

  printf("%d", (int)ceil(x * grad));
  return 0;
}
