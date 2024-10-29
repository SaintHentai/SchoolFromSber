#include "include/lexer.h"

#include <stdio.h>
#include <string.h>

#define MAX_TOKENS 100

// Функция для проверки, является ли символ оператором
int is_operator(char c) { return c == '+' || c == '-' || c == '*' || c == '/' || c == '^'; }

int is_space(char c) { return c == ' ' || c == '\t' || c == '\n' || c == '\r'; }

int is_digit(char c) { return c >= '0' && c <= '9'; }

// Функция для создания токена
Token create_token(TokenType type, const char* value) {
    Token token;
    token.type = type;
    strncpy(token.value, value, sizeof(token.value) - 1);
    token.value[sizeof(token.value) - 1] = '\0';
    return token;
}

// Лексический анализатор для разбора строки на токены
Token* tokenize(const char* expression, int* token_count) {
    static Token tokens[MAX_TOKENS];
    int index = 0;
    *token_count = 0;

    while (*expression != '\0') {
        if (is_space(*expression)) {
            // Пропускаем пробелы
            expression++;
        } else if (is_operator(*expression)) {
            // Обрабатываем операторы
            char operator_str[2] = {*expression, '\0'};
            tokens[index++] = create_token(OPERATOR, operator_str);
            expression++;
        } else if (*expression == '(') {
            tokens[index++] = create_token(LEFT_PAREN, "(");
            expression++;
        } else if (*expression == ')') {
            tokens[index++] = create_token(RIGHT_PAREN, ")");
            expression++;
        } else if (is_digit(*expression) || *expression == '.') {
            // Обрабатываем числа
            char number[32] = {0};
            int i = 0;
            while (is_digit(*expression) || *expression == '.') {
                number[i++] = *expression;
                expression++;
            }
            tokens[index++] = create_token(NUMBER, number);
        } else if (strncmp(expression, "sin", 3) == 0 || strncmp(expression, "cos", 3) == 0 ||
                   strncmp(expression, "tan", 3) == 0 || strncmp(expression, "ln", 2) == 0 ||
                   strncmp(expression, "ctg", 3) == 0 || strncmp(expression, "sqrt", 4) == 0) {
            // Обрабатываем функции
            if (strncmp(expression, "sin", 3) == 0) {
                tokens[index++] = create_token(FUNCTION, "sin");
                expression += 3;
            } else if (strncmp(expression, "cos", 3) == 0) {
                tokens[index++] = create_token(FUNCTION, "cos");
                expression += 3;
            } else if (strncmp(expression, "tan", 3) == 0) {
                tokens[index++] = create_token(FUNCTION, "tan");
                expression += 3;
            } else if (strncmp(expression, "ln", 2) == 0) {
                tokens[index++] = create_token(FUNCTION, "ln");
                expression += 2;
            } else if (strncmp(expression, "sqrt", 4) == 0) {
                tokens[index++] = create_token(FUNCTION, "sqrt");
                expression += 4;
            } else if (strncmp(expression, "ctg", 3) == 0) {
                tokens[index++] = create_token(FUNCTION, "ctg");
                expression += 3;
            }
        } else if (*expression == 'x') {
            // Переменная x
            tokens[index++] = create_token(VARIABLE, "x");
            expression++;
        } else {
            printf("Неизвестный символ: %c\n", *expression);
            exit(1);  // Ошибка
        }
    }

    *token_count = index;
    return tokens;
}
