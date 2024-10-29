#include <stdio.h>

int factorial(int n) {
  int res = 1;
  if (n != 0)
    for (int i = 1; i <= n; i++)
      res *= i;
  return res;
}

int binomal(int n, int k) {
  int res = factorial(n) / (factorial(k) * factorial(n - k));
  if (n < k || k < 0)
    res = 0;
  return res;
}

int main(void) {
  int n, result = 1;
  scanf("%d", &n);
  for (int k = 0; k <= n; k++) {
    result = binomal(n, k);
    if (k < n)
      printf("%d ", result);
  }
  printf("%d", result);
  return 0;
}
