#include <stdio.h>
#include <stdlib.h>

int find(int arr[], int size, int value);
void print(int arr[], int size);

int main(void) {
  int input;
  int size = 0;
  int capacity = 1;
  int status = 0;

  int *arr = NULL;
  arr = (int *)malloc(capacity * sizeof(int));
  if (arr == NULL)
    status = 1;

  if (status == 0) {
    while (scanf("%d", &input) == 1) {

      if (input == -1)
        break;

      if (status == 0 && find(arr, size, input)) {
        if (size == capacity) {
          capacity++;
          arr = (int *)realloc(arr, capacity * sizeof(int));
          if (arr == NULL)
            status = 1;
        }
        if (status == 0) {
          arr[size] = input;
          size++;
        }
      }
    }
  }
  if (status == 0) {
    print(arr, size);
  } else {
    printf("n/a");
    free(arr);
  }

  return status;
}

int find(int arr[], int size, int value) {
  int res = 1;
  for (int i = 0; i < size; i++)
    if (arr[i] == value)
      res = 0;
  return res;
}

void print(int arr[], int size) {
  for (int i = 0; i < size - 1; i++)
    printf("%d ", arr[i]);
  printf("%d", arr[size - 1]);
  free(arr);
}
