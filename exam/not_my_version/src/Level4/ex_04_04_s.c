#include <stdio.h>

// int chend() {
//     char ch = getchar();
//     return ch == '\n' || ch == ' ';
// }

// void output(long long unsigned int n);

// int main() {
//     long long int num = -1;
//     if (scanf("%lld", &num) && chend()) {
//         long long unsigned int n = num;
//         output(n);
//     } else
//         printf("n/a");

//     return 0;
// }

// void output(long long unsigned int n) {
//     unsigned int max = 0;
//     while (n / 10 != n) {
//         unsigned int temp = n % 10;
//         n = n / 10;
//         if (max < temp) max = temp;
//         // printf("%d\n", temp);
//     }
//     printf("%d", max);
// }

int main() {
    char max = '0', ch = getchar();
    if (ch == '-') ch = getchar();

    int is_valid = (ch >= '1' && ch <= '9');
    int ended = 0;

    if (ch == '0') {
        ch = getchar();
        if (ch == '\n' || ch == ' ' || ch == EOF) {
            is_valid = 1;
            ended = 1;
        }
    }

    while (is_valid && !ended) {
        // printf("%c\n", ch);
        if (max < ch) max = ch;
        ch = getchar();
        ended = (ch == '\n' || ch == EOF);
        is_valid = (ch >= '0' && ch <= '9') || ended;
    }

    if (is_valid && ended)
        printf("%c", max);
    else
        printf("n/a");
}