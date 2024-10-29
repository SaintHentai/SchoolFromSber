// Решено через посимвольное считывание потому что потому

#include <stdio.h>

int main() {
    char ch = getchar();
    if (ch == '-') ch = getchar();

    int result = 1, odd = 0, is_valid = (ch >= '0' && ch <= '9'), ended = 0;

    if (ch == '0') {
        ch = getchar();
        ended = ch == '\n' || ch == EOF;
    }

    while (is_valid && !ended) {
        int temp = ch - '0';
        if (temp % 2 == 1) {
            odd = 1;
            result *= temp;
        }
        is_valid = ch >= '0' && ch <= '9';
        ch = getchar();
        ended = ch == '\n' || ch == EOF;
    }

    if (!odd) result = 0;

    if (is_valid && ended)
        printf("%d", result);
    else
        printf("n/a");
}
