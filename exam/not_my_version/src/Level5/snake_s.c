// Заполнить "змейкой" матрицу заданной длины

#include <stdio.h>

int chend() {
    char ch = getchar();
    return ch == '\n' || ch == ' ' || ch == EOF;
}

void output(int n);

int main() {
    int n;
    if (scanf("%d", &n) && chend() && n >= 0) {
        output(n);
    } else
        printf("n/a");
    return 0;
}

void output(int n) {
    int matrix[n][n];

    int i = 0, j = 0;
    int j_left = 0, j_right = n - 1;
    int x = 1;
    for (int num = 1; num <= n * n; num++) {
        matrix[i][j] = num;
        if (x == 1) {
            if (j < j_right)
                j++;
            else {
                x = -1;
                i++;
            }
        } else if (x == -1) {
            if (j > j_left)
                j--;
            else {
                x = 1;
                i++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if (j < n - 1) printf(" ");
        }
        if (i < n - 1) printf("\n");
    }
}