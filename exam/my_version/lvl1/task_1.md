# Exam_01_01. Исправление ошибок №1.

## Задание

**Уровень:** 1  
**Темы:** базовые типы данных, объявление переменных, оператор присваивания.  
**Директория для решения:** src/  
**Файлы решения:** main.c  
**Входные данные:** стандартный поток ввода (stdin)  
**Выходные данные:** стандартный поток вывода (stdout)   

При написании программы была допущена ошибка. Необходимо исправить синтаксические, стилевые ошибки, не изменяя работу программы.  
В конце ответа не должно быть переноса на новую строку.

```c
#include <stdio.h>

int main(void)
{
	INT a, b;
	a = b = 1;

	scanf ("%d %d", &a, &b);
	printf("%d", a * b);

	return 0;
}
```

## Примеры

| Входные данные | Результат работы |  
| 2 2 | 4 |  
| -4 4 | -16 |  

**Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку materials/. Также обязательно проверяйте вашу программу на утечки памяти!
> [!WARNING]
> ИСПОЛЬЗУЙ clang-format

________________________________

# Exam_01_02. Исправление ошибок №2.

## Задание

**Уровень:** 1  
**Темы:** базовые типы данных, объявление переменных, оператор присваивания.  
**Директория для решения:** src/  
**Файлы решения:** main.c  
**Входные данные:** стандартный поток ввода (stdin)  
**Выходные данные:** стандартный поток вывода (stdout)  

При написании программы была допущена ошибка. Необходимо исправить синтаксические, стилевые ошибки, не изменяя работу программы. В конце ответа не должно быть переноса на новую строку.

```c
#include <stdio.h>

int main(void)
{
	int x1 = 1 x2 = 2;

	scanf("%d %d", &x1, &x2);
	printf("%d", x1 * x2);

	return 0;
}
```

## Примеры

| Входные данные | Результат работы |  
| 2 2 | 4 |  
| -4 4 | -16 |  

**Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку materials/. Также обязательно проверяйте вашу программу на утечки памяти!

________________________________

# Exam_01_03. Исправление ошибок №3.

## Задание

**Уровень:** 1  
**Темы:** базовые типы данных, объявление переменных, оператор присваивания.  
**Директория для решения:** src/  
**Файлы решения:** main.c  
**Входные данные:** стандартный поток ввода (stdin)  
**Выходные данные:** стандартный поток вывода (stdout)  

При написании программы была допущена ошибка. Необходимо исправить синтаксические, стилевые ошибки, не изменяя работу программы.  
В конце ответа не должно быть переноса на новую строку.

```c
#include <stdio.h>

int main(void)
{
	int: first = 3, second = 4;
	scanf("%d %d", &first, &second);
	printf("%d", first * second);

	return 0;
}
```

## Примеры

| Входные данные | Результат работы |  
| 2 2 | 4 |  
| -4 4 | -16 |  

**Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку materials/. Также обязательно проверяйте вашу программу на утечки памяти!

________________________________

# Exam_01_04. Исправление ошибок №4.

## Задание

**Уровень:** 1  
**Темы:** базовые типы данных, объявление переменных, оператор присваивания.  
**Директория для решения:** src/  
**Файлы решения:** main.c  
**Входные данные:** стандартный поток ввода (stdin)  
**Выходные данные:** стандартный поток вывода (stdout)  

При написании программы была допущена ошибка. Необходимо исправить синтаксические, стилевые ошибки, не изменяя работу программы.  
В конце ответа не должно быть переноса на новую строку.

```c
#include <stdio.h>

int main(void)
{
	int left = 2, int right = 1;
	scanf("%d %d", &left, &right);
	printf("%d", left * right);

	return 0;
}
```

## Примеры

| Входные данные | Результат работы |  
| 2 2 | 4 |  
| -4 4 | -16 |  

**Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку materials/. Также обязательно проверяйте вашу программу на утечки памяти!

________________________________

# Exam_01_05. Исправление ошибок №5.

## Задание

**Уровень:** 1  
**Темы:** базовые типы данных, объявление переменных, оператор присваивания.  
**Директория для решения:** src/  
**Файлы решения:** main.c  
**Входные данные:** стандартный поток ввода (stdin)  
**Выходные данные:** стандартный поток вывода (stdout)  

При написании программы была допущена ошибка. Необходимо исправить синтаксические, стилевые ошибки, не изменяя работу программы.  
В конце ответа не должно быть переноса на новую строку.

```c
#include <stdio.h>

int main(void)
{
	int x = 0; pi = 3.141;

	scanf("%d", &x);
	printf("%.2f"，pi * x);

	return 0;
}
```

## Примеры

| Входные данные | Результат работы |  
| 0 | 0.00 |  
| 2 | 6.28 |  

**Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку materials/. Также обязательно проверяйте вашу программу на утечки памяти!

________________________________

# Exam_01_06. Исправление ошибок №6.

## Задание

**Уровень:** 1  
**Темы:** базовые типы данных, объявление переменных, оператор присваивания.  
**Директория для решения:** src/  
**Файлы решения:** main.c  
**Входные данные:** стандартный поток ввода (stdin)  
**Выходные данные:** стандартный поток вывода (stdout)  

При написании программы была допущена ошибка. Необходимо исправить синтаксические, стилевые ошибки, не изменяя работу программы.  
В конце ответа не должно быть переноса на новую строку.

```c
#include <stdio.h>

int main(void)
{
	int value = 1;
	double pi = "3.141";

	scanf("%d", &value);
	printf("%.2f", value * pi);

	return 0;
}
```

## Примеры

| Входные данные | Результат работы |  
| 0 | 0.00 |  
| 2 | 6.28 |  

**Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку materials/. Также обязательно проверяйте вашу программу на утечки памяти!
