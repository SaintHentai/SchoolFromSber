#include <stdio.h>

int main(void) {
  int in;
  int cur = -1;
  int flag = 1;

  while (flag) {
    scanf("%d", &in);
    cur = (in > cur) ? in : cur;
    flag = (in == -1) ? 0 : 1;
  }

  printf("%d", cur);
  return 0;
}
