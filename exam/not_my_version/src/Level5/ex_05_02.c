#include <stdio.h>
#include <stdlib.h>

// НЕ ДОПИЛИЛ решение
int main() {
    int max = 0, min = 0, max_index = 0, min_index = 0;
    int i = 0;
    int* arr = NULL;

    // Чтение последовательности из stdin
    while (1) {
        int num;
        if (scanf("%d", &num) != 1) {
            printf("n/a\n");
            return 1;
        }
        if (num == -1) break;

        // Проверка на неотрицательность
        if (num < 0) {
            printf("n/a\n");
            return 1;
        }

        // Расширение массива
        arr = realloc(arr, (i + 1) * sizeof(int));
        if (arr == NULL) {
            printf("n/a\n");
            return 1;
        }
        arr[i] = num;

        // Обновление максимума и минимума
        if (i == 0 || num > max) {
            max = num;
            max_index = i;
        }
        if (i == 0 || num < min) {
            min = num;
            min_index = i;
        }

        i++;
    }

    // Проверка на наличие элементов
    if (i == 0) {
        printf("n/a\n");
        return 1;
    }

    // Перестановка максимума и минимума
    int temp = arr[max_index];
    arr[max_index] = arr[min_index];
    arr[min_index] = temp;

    // Вывод результата
    for (int j = 0; j < i; j++) {
        printf("%d ", arr[j]);
    }

    free(arr);
    return 0;
}