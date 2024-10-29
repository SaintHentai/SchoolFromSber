#include <stdio.h>
int main ()  // убери void он тут не нужен
{
	int x = 0;

	scanf ("%d", &x);  // добавь & для х
	printf("%05d", x);
	return 0;
}