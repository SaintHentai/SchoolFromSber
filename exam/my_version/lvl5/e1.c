#include <stdio.h>

int main(void) {
  int in, cur, sum = 0;

  scanf("%d", &in);
  int arr1[in];
  int arr2[in];
  for (int i = 0; i < in; i++) {
    scanf("%d", &arr1[i]);
  }
  for (int i = 0; i < in; i++) {
    scanf("%d", &arr2[i]);
  }
  for (int i = 0; i < in; i++) {
    cur = arr1[i] * arr2[i];
    sum = sum + cur;
  }

  printf("%d", sum);
  return 0;
}
