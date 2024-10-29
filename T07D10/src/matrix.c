#include <stdio.h>
#include <stdlib.h>

void input(int choice, int rows, int cols);
int read_matrix(int **matrix, int rows, int cols);
void print(int **matrix, int rows, int cols);
void createDynamicMatrix(int rows, int cols);
void createDynamicMatrix2(int rows, int cols);
void createDynamicMatrix3(int rows, int cols);
void createStaticMatrix(int rows, int cols);

int main() {
  int choice, rows, cols;
  if (scanf("%d", &choice) != 1 || choice <= 0 || getchar() != '\n') {
    printf("n/a");
    return 1;
  }
  if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 && cols <= 0 ||
      getchar() != '\n') {
    printf("n/a");
    return 1;
  }
  input(choice, rows, cols);

  return 0;
}

void input(int choice, int rows, int cols) {

  if (choice == 1) {
    createStaticMatrix(rows, cols);
  }
  if (choice == 2) {
    createDynamicMatrix(rows, cols);
  }
  if (choice == 3) {
    createDynamicMatrix2(rows, cols);
  }
  if (choice == 4) {
    createDynamicMatrix3(rows, cols);
  }
}

int read_matrix(int **matrix, int rows, int cols) {

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      if (scanf("%d", &matrix[i][j]) != 1)
        return 1;

  return 0;
}

void print(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void createDynamicMatrix(int rows, int cols) {
  int **matrix = malloc(rows * cols * sizeof(int) + rows * sizeof(int *));
  int *ptr = (int *)(matrix + rows);

  if (ptr == NULL) {
    printf("n/a");
    free(matrix);
  }

  for (int i = 0; i < rows; i++) {
    matrix[i] = ptr + cols * i;
  }

  if (read_matrix(matrix, rows, cols))
    printf("n/a");
  else
    print(matrix, rows, cols);

  free(matrix);
}

void createDynamicMatrix2(int rows, int cols) {
  int **matrix = (int **)malloc(rows * sizeof(int *));
  if (matrix == NULL) {
    free(matrix);
    printf("n/a");
  }

  for (int i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(cols * sizeof(int));
    if (matrix[i] == NULL) {
      printf("n/a");
      for (int j = 0; j < i; j++) {
        free(matrix[j]);
      }
      free(matrix);
    }
  }

  if (read_matrix(matrix, rows, cols))
    printf("n/a");
  else
    print(matrix, rows, cols);

  for (int i = 0; i < rows; i++)
    free(matrix[i]);

  free(matrix);
}

void createDynamicMatrix3(int rows, int cols) {
  int **matrix = (int **)malloc(rows * sizeof(int *));
  int *values_array = malloc(rows * cols * sizeof(int));

  if (matrix == NULL || values_array == NULL) {
    printf("n/a");
    free(values_array);
    free(matrix);
  }

  for (int i = 0; i < rows; i++)
    matrix[i] = values_array + cols * i;

  if (read_matrix(matrix, rows, cols))
    printf("n/a");
  else
    print(matrix, rows, cols);

  free(values_array);
  free(matrix);
}

void createStaticMatrix(int rows, int cols) {
  int matrix[rows][cols];

  if (rows > 100 || cols > 100) {
    printf("n/a");
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (scanf("%d", &matrix[i][j]) != 1) {
        printf("n/a");
      }
    }
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}
