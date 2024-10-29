#include "polish.h"

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
