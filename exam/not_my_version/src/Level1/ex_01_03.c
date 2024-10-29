#include <stdio.h>

int main(void)
{
	int first = 3;  // ВАЖНО! Поставить ; объявить переменную типа int  
    int second = 4; // ВАЖНО! Смотри задания

	scanf("%d %d", &first, &second);
	printf("%d", first * second);

	return 0;
}