// Заполнить "спиралькой" матрицу заданной длины

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
    int i_top = 0, i_bottom = n - 1, j_left = 0, j_right = n - 1;
    int x = 1, y = 0;
    for (int num = 1; num <= n * n; num++) {
        matrix[i][j] = num;
        if (x == 1) {
            if (j < j_right)
                j++;
            else {
                x = 0;
                y = 1;
                i++;
                i_top = i;
            }
        } else if (x == -1) {
            if (j > j_left)
                j--;
            else {
                x = 0;
                y = -1;
                i--;
                i_bottom = i;
            }
        } else if (y == 1) {
            if (i < i_bottom)
                i++;
            else {
                y = 0;
                x = -1;
                j--;
                j_right = j;
            }
        } else if (y == -1) {
            if (i > i_top)
                i--;
            else {
                y = 0;
                x = 1;
                j++;
                j_left = j;
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