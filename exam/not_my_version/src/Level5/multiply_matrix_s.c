// Вывести произведение двух равноразмерных матриц

#include <stdio.h>

int chend() {
    char ch = getchar();
    return ch == '\n' || ch == ' ' || ch == EOF;
}

int scan_valid(int *num) { return scanf("%d", num) && chend(); }

int input_matrix(int n, int m, int matrix[n][m]);

void output(int n, int m, int matrix1[n][m], int matrix2[n][m]);

int main() {
    int n, m, is_valid = 1;
    if (scan_valid(&n) && scan_valid(&m) && n >= 0 && m >= 0) {
        int matrix1[n][m], matrix2[n][m];
        if (input_matrix(n, m, matrix1) && input_matrix(n, m, matrix2))
            output(n, m, matrix1, matrix2);
        else
            is_valid = 0;
    } else
        is_valid = 0;

    if (!is_valid) printf("n/a");

    return 0;
}

int input_matrix(int n, int m, int matrix[n][m]) {
    int is_valid = 1;
    for (int i = 0; is_valid && i < n; i++) {
        for (int j = 0; is_valid && j < m; j++) {
            if (!scan_valid(&matrix[i][j])) is_valid = 0;
        }
    }
    return is_valid;
}

void output(int n, int m, int matrix1[n][m], int matrix2[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix1[i][j] * matrix2[i][j]);
            if (j < m - 1) printf(" ");
        }
        if (i < n - 1) printf("\n");
    }
}