#include <stdio.h>

int main(void)
{
	int left = 2;    // ВАЖНО! добовляем ; и объявляем переменную типа int
    int right = 1;

	scanf("%d %d", &left, &right);
	printf("%d", left * right);

	return 0;
}