#include <stdio.h>
unsigned long long int binom(int, int);
int main() {
    int n;
    if (scanf("%d", &n) != 1 || getchar() != '\n') {  // проверка на ввдеенное значение и на символы
        printf("n/a");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%lld ", binom(n, i));
        }
        printf("%lld", binom(n, n));
    }
}

unsigned long long int binom(int n, int k) {  // поиск биноменального коэф: n! / (k! * (n - k)! )
    unsigned long long int bin = 1;
    for (int i = 0; i < k; i++) {
        bin *= (n - i);
        bin /= (i + 1);
    }
    return bin;
}