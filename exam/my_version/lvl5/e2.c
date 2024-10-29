#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *arr = NULL;
  int input;
  int size = 0;
  int capacity = 1;

  arr = (int *)malloc(capacity * sizeof(int));
  if (arr == NULL) {
    printf("a/n");
    return 1;
  }

  while (scanf("%d", &input) == 1) {
    if (input == -1)
      break;

    if (size == capacity) {
      capacity++;
      arr = (int *)realloc(arr, capacity * sizeof(int));
      if (arr == NULL) {
        printf("a/n");
        return 1;
      }
    }

    arr[size] = input;
    size++;
  }

  int head = 0;
  int tail = size - 1;

  while (head <= tail) {
    if (head == tail) {
      printf("%d", arr[head]);
    } else {
      printf("%d %d ", arr[head], arr[tail]);
    }
    head++;
    tail--;
  }

  free(arr);

  return 0;
}
