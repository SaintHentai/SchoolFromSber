#include <stdio.h>

int main(void) {
    int a, b;  // ВАЖНО! INT меняем на int в общем-то и всё
    a = b = 1;

    scanf("%d %d", &a, &b);
    printf("%d", a * b);

    return 0;
}