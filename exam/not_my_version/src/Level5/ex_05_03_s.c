#include <stdio.h>
#include <stdlib.h>

int chend() {
    char ch = getchar();
    return ch == '\n' || ch == ' ' || ch == EOF;
}

void output(int *data, int n);

int main() {
    int *data = malloc(sizeof(int));
    int num = 0, i = -1;
    int is_valid = 1, ended = 0;

    while (!ended && is_valid) {
        if (!scanf("%d", &num) || !chend()) is_valid = 0;
        if (is_valid && num >= 0) {
            i++;
            data = realloc(data, (i + 1) * sizeof(int));
            data[i] = num;
        } else if (num == -1)
            ended = 1;
        else
            is_valid = 0;
    }

    int n = i + 1;

    if (ended && is_valid) {
        if (n > 0) output(data, n);
    } else
        printf("n/a");

    free(data);

    return 0;
}

void output(int *data, int n) {
    int k = n / 2;
    if (n % 2 == 1) k++;
    for (int i = 0; i < k; i++) {
        printf("%d ", data[i]);
        if (i < n - 1 - i) printf("%d", data[n - 1 - i]);
        if (i < k - 1) printf(" ");
    }
}