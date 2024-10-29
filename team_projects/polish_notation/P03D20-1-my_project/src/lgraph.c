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
int is_digit(char c) { return c >= '0' && c <= '9'; }

// Проверка, является ли символ буквой
int is_alpha(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Лексический анализатор (разбор строки на токены)
int tokenize(const char *expression, Token *tokens) {
  int i = 0;
  int token_count = 0;

  while (expression[i] != '\0') {
    if (expression[i] == ' ' || expression[i] == '\t' ||
        expression[i] == '\n') {
      i++;
      continue;
    }

    if (is_digit(expression[i])) {
      tokens[token_count].type = TOKEN_NUMBER;
      tokens[token_count].value = strtod(&expression[i], NULL);
      token_count++;
      while (is_digit(expression[i]) || expression[i] == '.')
        i++;
    } else if (strchr("+-*/^", expression[i])) {
      tokens[token_count].type = TOKEN_OPERATOR;
      tokens[token_count].op = expression[i];
      token_count++;
      i++;
    } else if (expression[i] == 'x') {
      tokens[token_count].type = TOKEN_VARIABLE;
      token_count++;
      i++;
    } else if (expression[i] == '(') {
      tokens[token_count].type = TOKEN_LEFT_PAREN;
      token_count++;
      i++;
    } else if (expression[i] == ')') {
      tokens[token_count].type = TOKEN_RIGHT_PAREN;
      token_count++;
      i++;
    } else if (is_alpha(expression[i])) {
      tokens[token_count].type = TOKEN_FUNCTION;
      int func_len = 0;
      while (is_alpha(expression[i])) {
        tokens[token_count].func[func_len++] = expression[i++];
      }
      tokens[token_count].func[func_len] = '\0';
      token_count++;
    } else {
      printf("Unknown character: %c\n", expression[i]);
      return -1;
    }
  }

  return token_count;
}

// Определение приоритета операторов
int precedence(char op) {
  switch (op) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  default:
    return 0;
  }
}

// Проверка на левоассоциативность операторов
int is_left_associative(char op) {
  return (op == '+' || op == '-' || op == '*' || op == '/');
}

// Перевод в обратную польскую нотацию (ОПН)
void to_rpn(Token *tokens, int token_count, Token *output, int *output_count) {
  Token stack[MAX_TOKENS];
  int stack_top = -1;
  int out_index = 0;

  for (int i = 0; i < token_count; i++) {
    Token token = tokens[i];

    if (token.type == TOKEN_NUMBER || token.type == TOKEN_VARIABLE) {
      output[out_index++] = token;
    } else if (token.type == TOKEN_FUNCTION) {
      stack[++stack_top] = token;
    } else if (token.type == TOKEN_OPERATOR) {
      while (stack_top >= 0 && stack[stack_top].type == TOKEN_OPERATOR &&
             ((is_left_associative(token.op) &&
               precedence(token.op) <= precedence(stack[stack_top].op)) ||
              (!is_left_associative(token.op) &&
               precedence(token.op) < precedence(stack[stack_top].op)))) {
        output[out_index++] = stack[stack_top--];
      }
      stack[++stack_top] = token;
    } else if (token.type == TOKEN_LEFT_PAREN) {
      stack[++stack_top] = token;
    } else if (token.type == TOKEN_RIGHT_PAREN) {
      while (stack_top >= 0 && stack[stack_top].type != TOKEN_LEFT_PAREN) {
        output[out_index++] = stack[stack_top--];
      }
      stack_top--; // Удаляем левую скобку
    }
  }

  while (stack_top >= 0) {
    output[out_index++] = stack[stack_top--];
  }

  *output_count = out_index;
}

// Применение операторов
double apply_operator(double a, double b, char op) {
  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    return a / b;
  case '^':
    return pow(a, b);
  default:
    return 0;
  }
}

// Применение функций (sin, cos и др.)
double apply_function(const char *func, double x) {
  if (strcmp(func, "sin") == 0)
    return sin(x);
  if (strcmp(func, "cos") == 0)
    return cos(x);
  if (strcmp(func, "tan") == 0)
    return tan(x);
  if (strcmp(func, "sqrt") == 0)
    return sqrt(x);
  if (strcmp(func, "ctg") == 0)
    return 1.0 / tan(x);
  if (strcmp(func, "ln") == 0)
    return log(x);
  return 0;
}

// Вычисление выражения в обратной польской нотации
double evaluate_rpn(Token *rpn_tokens, int rpn_count, double x) {
  double stack[MAX_TOKENS];
  int stack_top = -1;

  for (int i = 0; i < rpn_count; i++) {
    Token token = rpn_tokens[i];

    if (token.type == TOKEN_NUMBER) {
      stack[++stack_top] = token.value;
    } else if (token.type == TOKEN_VARIABLE) {
      stack[++stack_top] = x;
    } else if (token.type == TOKEN_OPERATOR) {
      double b = stack[stack_top--];
      double a = stack[stack_top--];
      stack[++stack_top] = apply_operator(a, b, token.op);
    } else if (token.type == TOKEN_FUNCTION) {
      double a = stack[stack_top--];
      stack[++stack_top] = apply_function(token.func, a);
    }
  }

  return stack[stack_top];
}

// Функция для отрисовки графика
void draw_graph(Token *rpn_tokens, int rpn_count) {
  char graph[HEIGHT][WIDTH];

  // Инициализация пустого поля
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      graph[y][x] = '.';
    }
  }

  // Вычисляем значения функции и рисуем график
  for (int i = 0; i < WIDTH; i++) {
    double x = (4 * PI * i) / WIDTH; // Преобразуем x в диапазон [0; 4 * PI]
    double y = evaluate_rpn(rpn_tokens, rpn_count, x);

    int plot_x = i;
    int plot_y = (int)(HEIGHT / 2 -
                       (y * (HEIGHT / 2))); // Преобразуем y в диапазон [-1; 1]

    if (plot_y >= 0 && plot_y < HEIGHT) {
      graph[plot_y][plot_x] = '*'; // Рисуем график
    }
  }

  // Выводим поле с графиком
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      printf("%c", graph[y][x]);
    }
    printf("\n");
  }
}

// Основная функция
int main() {
  char input[100];
  fgets(input, sizeof(input), stdin);
  const char *expression =
      input; // "sin(cos(2*x))"; Пример выражения для графика

  Token tokens[MAX_TOKENS];
  int token_count = tokenize(expression, tokens);

  if (token_count < 0) {
    printf("Ошибка при разборе выражения!\n");
    return 1;
  }

  Token rpn_tokens[MAX_TOKENS];
  int rpn_count = 0;
  to_rpn(tokens, token_count, rpn_tokens, &rpn_count);

  // Рисуем график
  draw_graph(rpn_tokens, rpn_count);

  return 0;
}
