#include <stdio.h>
#include <math.h>

// Функция для проверки, является ли число простым
int is_prime(int num) {
  if (num < 2) return 0;

  for (int i = 2; i < num; i++) {
    int cur = num;

    while (cur >= i) {
      cur -= i;
    }

    if (cur == 0) {
      return 0;  // Нашли делитель, значит число не простое
    }
  }

  return 1;  // Если не нашли делителей, значит число простое
}

// Функция для нахождения наибольшего простого делителя
int largest_prime_divisor(int a) {
  int divisors[1000];  // Массив для хранения делителей
  int primes[1000];  // Массив для хранения простых делителей
  int div_count = 0;  // Счетчик для массива делителей
  int prime_count = 0;  // Счетчик для массива простых делителей

  // Находим все делители числа a
  for (int i = 2; i < a; i++) {
    for (int j = 2; j < a; j++) {
      int cur = a - (i * j);

      if (cur == 0) {
        divisors[div_count++] = i;  // Число i является делителем
      }
    }
  }

  // Проверяем, какие из делителей простые
  for (int i = 0; i < div_count; i++) {
    if (is_prime(divisors[i])) {
      primes[prime_count++] = divisors[i];
    }
  }

  // Находим наибольший простой делитель
  int largest_prime = -1;
  for (int i = 0; i < prime_count; i++) {
    if (primes[i] > largest_prime) {
      largest_prime = primes[i];
    }
  }

  return largest_prime;
}

int main() {
  int a;
  scanf("%d", &a);
  fabs(a);



  int result = largest_prime_divisor(a);
  if (result != -1) {
    printf("%d\n", result);
  } else {
    printf("n/a\n");
  }

  return 0;
}
