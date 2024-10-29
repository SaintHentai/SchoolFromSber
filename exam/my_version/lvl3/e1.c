#include <math.h>
#include <stdio.h>

#define p 21500

int main(void) {
  double r, result;
  scanf("%lf", &r);

  result = round(r);

  printf("%0.lf", result);
  return 0;
}

double round(double x) {
  double m;
  m = p * (4.0 / 3.0) * M_PI * pow(x, 3);
  return m;
}
