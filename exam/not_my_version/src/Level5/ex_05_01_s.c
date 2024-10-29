#include <stdio.h>
#include <stdlib.h>

int chend() {
    char ch = getchar();
    return ch == '\n' || ch == ' ' || ch == EOF;
}

int scan_valid(int* num) { return scanf("%d", num) && chend(); }

void output(int* vec1, int* vec2, int n);

int main() {
    int n = 0, is_valid = 1;

    if (!scan_valid(&n) || n <= 0) is_valid = 0;

    int* vec1 = malloc(n * sizeof(int));  // Можно и через статическую память
    int* vec2 = malloc(n * sizeof(int));

    for (int i = 0; is_valid && i < n; i++) {
        if (!scan_valid(&vec1[i])) is_valid = 0;
    }
    for (int i = 0; is_valid && i < n; i++) {
        if (!scan_valid(&vec2[i])) is_valid = 0;
    }

    if (is_valid)
        output(vec1, vec2, n);
    else
        printf("n/a");

    free(vec1);
    free(vec2);

    return 0;
}

void output(int* vec1, int* vec2, int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += vec1[i] * vec2[i];
    }
    printf("%d", result);
}