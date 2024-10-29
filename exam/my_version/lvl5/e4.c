#include <stdio.h>
#include <stdlib.h>

void print(int arr[], int size);

int main(void) {
  int *arr = NULL;
  int input;
  int size = 0;
  int status = 0;
  int capacity = 1;

  arr = (int *)malloc(capacity * sizeof(int));
  if (arr == NULL)
    status = 1;

  if (status == 0) {
    while (scanf("%d", &input) == 1) {

      if (input == -1)
        break;

      if (status == 0 && size == capacity) {
        capacity = capacity * 2;
        arr = (int *)realloc(arr, capacity * sizeof(int));
        if (arr == NULL) {
          status = 1;
        }
      }
      if (status == 0) {
        arr[size] = input;
        size++;
      }
    }
  }
  if (status == 0) {
    print(arr, size);
  } else {
    printf("n/a");
  }
  free(arr);

  return status;
}

void print(int arr[], int size) {
  if (1 < size) {
    for (int i = size - 1; i >= 1; i--) {
      printf("%d ", arr[i]);
    }
  }
  printf("%d", arr[0]);
}
