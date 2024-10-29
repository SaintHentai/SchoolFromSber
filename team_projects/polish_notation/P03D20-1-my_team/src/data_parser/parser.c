#include "parser.h"

int input(char *str) {  // НУ инпут это инпут
    int flag = 1;
    char ch = '\0';
    int i = 0;
    while (scanf("%c", &ch) == 1 && strchr(STR_ALLOW, ch) != NULL && flag && ch != '\n' && ch != EOF &&
           ch != -1) {
        if (strchr(STR_ALLOW, ch) != NULL) {
            str[i] = ch;
            i++;
        } else {
            flag = 0;
            break;
        }
    }
    if (ch != '\n') flag = 0;
    return flag;
}

int checking_brackets(char *str) {  // проверка на скобки ее писать было ужасно
    int t = 0;
    for (int i = 0; i < (int)strlen(str); i++) {
        if (str[i] == '(') {
            t++;
        } else if (str[i] == ')') {
            t--;
            if (t < 0) t = -228;
        }
    }
    return (t == 0) ? 1 : 0;  // если закрывающих скобок было больше то 0;
}

int get_digit(char **str, double *d) {
    int flag = 1;
    int i = 0;
    int t = 0;
    while (strchr(IS_DIGIT, *(*str + i)) != NULL && flag) {
        if (i > 0 && *(*str + i) == '-') {
            break;
        }
        if (*(*str + i) == '.') {
            t++;
            if (t > 1) {
                flag = 0;
            }
        }
        i++;
    }
    char tmp[STR_MAX] = {'\0'};
    memcpy(tmp, *str, i);
    if (sscanf(tmp, "%lf", d) != 1) {
        flag = 0;
    }
    *str += (i - 1);
    return flag;
}

int get_function(char **str, char *ch) {  // Вобщем эта функция отвечает за ввод математических элементов типа
                                          // cos sin tg и тому подобное возвращая обработанное значения
    int flag = 1;
    char *lstr = strchr(*str, '(');
    if (lstr != NULL) {
        int len = (int)(lstr - *str);
        if (len > 4) {
            flag = 0;
        } else {
            char tmp[STR_MAX] = {'\0'};
            memcpy(tmp, *str, len);
            if (strcmp(tmp, "sin") == 0) {
                *ch = 's';
            } else if (strcmp(tmp, "cos") == 0) {
                *ch = 'c';
            } else if (strcmp(tmp, "tg") == 0) {
                *ch = 't';
            } else if (strcmp(tmp, "ctg") == 0) {
                *ch = 'g';
            } else if (strcmp(tmp, "sqrt") == 0) {  // прошу прощения за такую грязь
                *ch = 'q';
            } else if (strcmp(tmp, "ln") == 0) {
                *ch = 'l';
            } else {
                flag = 0;
            }
            *str += (len - 1);
        }
    }
    return flag;
}

int parse(char *str, stack **head) {  // а вот и добавление уже проверенных символов в стек
    int flag = 1;
    char ch_m = '\0';
    while (*str && flag) {
        if (*str == 'x') {
            add_last(head, 'x', 0);
        } else if (strchr(IS_ACTION, *str) != NULL) {
            add_last(head, *str, 0);
        } else if (*str == '-') {
            if (ch_m != '\0' && (strchr(IS_ACTION, ch_m) == NULL)) {
                add_last(head, *str, 0);
            } else {
                double d = 0;
                flag = get_digit(&str, &d);
                add_last(head, 'd', d);
            }
        } else if (strchr(IS_DIGIT, *str) != NULL) {
            double d = 0;
            flag = get_digit(&str, &d);
            add_last(head, 'd', d);
        } else if (*str != '\0' && *str != '\n') {
            char ch = '\0';
            flag = get_function(&str, &ch);
            add_last(head, ch, 0);
        }
        ch_m = *str;
        str++;
    }
    if (*head == NULL) {
        flag = 0;
    }
    return flag;
}
