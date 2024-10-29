#ifndef POLISH_H
#define POLISH_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define WIDTH 80
#define HEIGHT 25
#define PI 3.14159265358979323846

typedef enum {
  TOKEN_NUMBER,
  TOKEN_OPERATOR,
  TOKEN_FUNCTION,
  TOKEN_VARIABLE,
  TOKEN_LEFT_PAREN,
  TOKEN_RIGHT_PAREN
} TokenType;

typedef struct {
  TokenType type;
  double value;  // Для чисел
  char op;       // Для операторов
  char func[10]; // Для функций
} Token;

// Проверка, является ли символ числом
int is_digit(char c);

// Проверка, является ли символ буквой
int is_alpha(char c);

// Лексический анализатор (разбор строки на токены)
int tokenize(const char *expression, Token *tokens);

// Определение приоритета операторов
int precedence(char op);

// Проверка на левоассоциативность операторов
int is_left_associative(char op);

// Перевод в обратную польскую нотацию (ОПН)
void to_rpn(Token *tokens, int token_count, Token *output, int *output_count);

// Применение операторов
double apply_operator(double a, double b, char op);

// Применение функций (sin, cos и др.)
double apply_function(const char *func, double x);

// Вычисление выражения в обратной польской нотации
double evaluate_rpn(Token *rpn_tokens, int rpn_count, double x);

// Функция для отрисовки графика
void draw_graph(Token *rpn_tokens, int rpn_count);

#endif
