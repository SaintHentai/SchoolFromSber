// Возвести элементы матрицы в квадрат

#include <stdio.h>

int chend() {
    char ch = getchar();
    return ch == '\n' || ch == ' ' || ch == EOF;
}

int scan_valid(int *num) { return scanf("%d", num) && chend(); }

int input_matrix(int n, int m, int matrix[n][m]);

void output(int n, int m, int matrix[n][m]);

int main() {
    int n, m, is_valid = 1;
    if (scan_valid(&n) && scan_valid(&m) && n >= 0 && m >= 0) {
        int matrix[n][m];
        if (input_matrix(n, m, matrix))
            output(n, m, matrix);
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
            if (scan_valid(&matrix[i][j]))
                matrix[i][j] *= matrix[i][j];
            else
                is_valid = 0;
        }
    }
    return is_valid;
}

void output(int n, int m, int matrix[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if (j < m - 1) printf(" ");
        }
        if (i < n - 1) printf("\n");
    }
}