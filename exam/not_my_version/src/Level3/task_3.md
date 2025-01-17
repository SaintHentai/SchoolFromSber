# Exam_03_01. Платиновый шар.

## Задание

**Уровень:** 2  
**Темы:** типы данных, переменные, выражения, логические операции и математические функции.  
**Директория для решения:** src/  
**Файлы решения:** main.c  
**Входные данные:** стандартный поток ввода (stdin)  
**Выходные данные:** стандартный поток вывода (stdout)  

Написать программу, вычисляющую массу шара в килограммах, состоящего полностью из платины. Радиус шара (в метрах, вещественное число) задается на стандартном
потоке ввода stdin, а плотность платины составляет 21500 `кг/м^3`. Результат вычисления округлить по целого числа и вывести на стандартный поток вывода stdout. Проверить на валидность введенные данные. В случае любой ошибки выводить "n/a".

**Примечание:** формула объема шара: `V = (4 / 3) * рі * R^3`  

**Примечание:** формула плотности: `P = m / V`  

**Примечание:** В этом задании важна точность, поэтому советуем использовать константу `М_PI` (содержащую число пи) и функцию `double round (double x);` из библиотеки `<math.h>`, а также `double` вместо `float`.  

Вывод должен выглядеть таким образом - `printf("%.0lf", result);`

## Примеры

| Входные данные | Результат работы |  
| 1 | 90059 |  
| 10 | 90058989 |  

**Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку materials/. Также обязательно проверяйте вашу программу на утечки памяти!

________________________________

# Exam_03_02. Перевод в градусную меру.

## Задание

**Уровень:** 2  
**Темы:** типы данных, переменные, выражения, логические операции и математические функции.  
**Директория для решения:** src/  
**Файлы решения:** main.c  
**Входные данные:** стандартный поток ввода (stdin)  
**Выходные данные:** стандартный поток вывода (stdout)  

Написать программу, осуществляющую перевод величины из радианной меры в градусную. Радианная мера (вещественное число) задается на стандартном потоке ввода stdin, результат перевода необходимо математически округлить до целого числа и вывести на стандартный поток вывода stdout. В конце ответа не должно быть переноса на новую строку. Проверить на валидность введенные данные. В случае любой ошибки выводить "n/a".

**Примечание:** в одном радиане 57.29 градусов.

## Примеры

| Входные данные | Результат работы |  
| 1 | 57 |  
| 2 | 115 |  

**Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку materials/. Также обязательно проверяйте вашу программу на утечки памяти!

________________________________

# Exam_03_03. Перестановка цифр.

## Задание

**Уровень:** 4  
**Темы:** типы данных, переменные, выражения, логические операции и математические функции.  
**Директория для решения:** src/  
**Файлы решения:** main.c  
**Входные данные:** стандартный поток ввода (stdin)  
**Выходные данные:** стандартный поток вывода (stdout)  

Написать программу, осуществляющую перестановку крайних цифр в целом трехзначном числе. Целое трехзначное число задается на стандартном потоке ввода stdin, результат перестановки выводится в виде трехзначного числа с учетом ведущих нулей на стандартный поток вывода stdout.  В конце
ответа не должно быть переноса на новую строку.

**Примечание:** гарантируется, что на вход программе всегда подается целое трехзначное число.

## Примеры

| Входные данные | Результат работы |  
| 159 | 951 |  
| 120 | 021 |  
| -123 | -321 |  

**Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку materials/. Также обязательно проверяйте вашу программу на утечки памяти!

________________________________

# Exam_03_04. Inside the interval

## Задание

**Уровень:** 3  
**Темы:** типы данных, переменные, выражения, логические операции и математические функции.  
**Директория для решения:** src/  
**Файлы решения:** main.c  
**Входные данные:** стандартный поток ввода (stdin)  
**Выходные данные:** стандартный поток вывода (stdout)  

Три целых числа (A, B и C) задаются на стандартном потоке ввода stdin, необходимо вывести на стандартный поток вывода stdout `1`  в случае если С находится строго между A и B, в противном случае вывести `0`. В конце ответа не должно быть переноса на новую строку. Проверить на валидность введенные данные. В случае любой ошибки выводить "n/a".

**Внимание:** условный оператор if может использоваться только для обработки ошибочного ввода.

## Примеры

| Входные данные | Результат работы |  
| 0 9 4 | 1 |  
| 0 1 4 | 0 |  
| 0 0 0 | 0 |  

**Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку materials/. Также обязательно проверяйте вашу программу на утечки памяти!

________________________________

# Exam_03_05. Логическое выражение

## Задание


**Уровень:** 2  
**Темы:** типы данных, переменные, выражения, логические операции и математические функции.  
**Директория для решения:** src/  
**Файлы решения:** main.c  
**Входные данные:** стандартный поток ввода (stdin)  
**Выходные данные:** стандартный поток вывода (stdout)  

На стандартный поток ввода stdin поступают числа х, у и z, каждое из которых может принимать одно из двух значений (0 и 1). Необходимо вывести на стандартный поток вывода stdout единицу, если значение следуюдего выражения истинно: x and (z or y), в противном случае вывести ноль. В конце ответа не должно быть переноса на новую строку. Проверить на валидность введенные
данные. В случае любой ошибки выводить "n/a".


## Примеры
| Входные данные | Результат работы |  
| 1 1 1 | 1 |  
| 0 0 0 | 0 |  

**Внимание:** Мы любезно напоминаем вам, что процедура тестирования вашей программы включает анализ стиля кода. Пожалуйста, загляните в папку materials/. Также обязательно проверяйте вашу программу на утечки памяти!
