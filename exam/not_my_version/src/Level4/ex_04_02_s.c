#include <stdio.h>
#include <stdlib.h>

int chend() {
    char ch = getchar();
    return ch == '\n' || ch == ' ' || ch == EOF;
}

int main() {
    int is_valid = 1;
    long long int num = -1, max = -1;
    while (is_valid && scanf("%lld", &num) && chend() && num != -1) {
        if (num < 0)
            is_valid = 0;
        else if (max < num)
            max = num;
    }
    if (is_valid && max != -1)
        printf("%lld", max);
    else
        printf("n/a");
}
