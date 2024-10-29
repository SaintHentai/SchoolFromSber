#include <stdio.h>
#include <stdlib.h>

int input(int *a, int *n);
void insertionSort(int *arr, int size);
void output(int *arr, int size);

int main() {
  int n;
  // || getchar() != '\n'
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("n/a\n");
    return 1;
  }

  int *arr = (int *)malloc(n * sizeof(int));
  if (arr == NULL) {
    printf("n/a\n");
    return 1;
  }

  if (input(arr, &n)) {
    insertionSort(arr, n);
    output(arr, n);
  } else {
    printf("n/a\n");
    free(arr);
    return 1;
  }

  free(arr);
  return 0;
}

int input(int *a, int *n) {

  for (int *p = a; p - a < *n; p++) {
    if (scanf("%d", p) == 1) {
      if (p - a + 1 == *n && getchar() != '\n') {
        // printf("n/a");
        return 0;
      }
    } else {
      // printf("n/a");
      return 0;
    }
  }
  return 1;
}

void insertionSort(int *arr, int size) {
  for (int out = 1; out < size; out++) {
    int next = arr[out];
    int in = out;

    while (in > 0 && arr[in - 1] > next) {
      arr[in] = arr[in - 1];
      in--;
    }

    arr[in] = next;
  }
}

void output(int *arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    printf("%d ", arr[i]);
  }
  printf("%d", arr[size - 1]);
}
