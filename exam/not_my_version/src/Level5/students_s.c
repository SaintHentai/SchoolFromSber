// Вход: число студентов
//       имя1
//       балл1
//       имя2
//       балл2
//       ...
// Выход: *через запятую имена студентов, с баллом выше среднего*
// По условию прямо требуется создать структуры для каждого студента.

#include <stdio.h>
#include <stdlib.h>

#define NMAX 20

struct student {
    char name[NMAX];
    int score;
};

int chend() {
    char ch = getchar();
    return ch == '\n' || ch == ' ';
}

int scan_valid(int* num) { return scanf("%d", num) && chend(); }

int input_and_calc_average(struct student** studs, int n, double* average);
void output(struct student* studs, int n, double average);

int main() {
    int n = 0, is_valid = 1, dyn_alloc = 0;
    struct student* studs;
    double average = 0;

    if (scanf("%d", &n) && chend()) {
        studs = malloc(n * sizeof(struct student));
        dyn_alloc = 1;
    } else
        is_valid = 0;

    if (is_valid && input_and_calc_average(&studs, n, &average)) output(studs, n, average);

    if (dyn_alloc) free(studs);

    if (!is_valid) printf("n/a");

    return 0;
}

int input_and_calc_average(struct student** studs, int n, double* average) {
    int is_valid = 1;
    for (int i = 0; is_valid && i < n; i++) {
        if (scanf("%20s", (*studs)[i].name) && chend() && scanf("%d", &((*studs)[i].score)) && chend()) {
            *average += (*studs)[i].score;
        } else
            is_valid = 0;
    }
    *average /= n;

    return is_valid;
}

void output(struct student* studs, int n, double average) {
    int first = 1;
    for (int i = 0; i < n; i++) {
        if (studs[i].score >= average) {
            if (!first)
                printf(", ");
            else
                first = 0;
            printf("%s", studs[i].name);
        }
    }
}