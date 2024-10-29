#include "include/evaluator.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/lexer.h"
#include "include/math_ops.h"
#include "include/stack.h"

// Функция для вычисления выражения в ОПН
double evaluate_rpn(const Token* rpn_tokens, int rpn_count, double x_value) {
    Stack* values = create_stack(MAX_TOKENS);

    for (int i = 0; i < rpn_count; ++i) {
        Token token = rpn_tokens[i];
        if (token.type == NUMBER) {
            push(values, token);
        } else if (token.type == VARIABLE) {
            TokenType type = VARIABLE;
            Token var_token = create_token(type, "x");
            snprintf(var_token.value, sizeof(var_token.value), "%lf", x_value);
            push(values, var_token);
        } else if (token.type == OPERATOR) {
            double b = atof(pop(values).value);
            double a = atof(pop(values).value);
            double result;

            switch (token.value[0]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    result = a / b;
                    break;
                case '^':
                    result = pow(a, b);
                    break;
                default:
                    exit(1);  // Неподдерживаемый оператор // Добавить сообщение об ошибке
            }
            Token result_token = create_token(OPERATOR, "");
            snprintf(result_token.value, sizeof(result_token.value), "%lf", result);
            push(values, result_token);
        } else if (token.type == FUNCTION) {
            double arg = atof(pop(values).value);
            double result;

            if (strcmp(token.value, "sin") == 0) {
                result = calculate_sin(arg);
            } else if (strcmp(token.value, "cos") == 0) {
                result = calculate_cos(arg);
            } else if (strcmp(token.value, "tan") == 0) {
                result = calculate_tan(arg);
            } else if (strcmp(token.value, "ctg") == 0) {
                result = calculate_ctg(arg);
            } else if (strcmp(token.value, "sqrt") == 0) {
                result = calculate_sqrt(arg);
            } else if (strcmp(token.value, "ln") == 0) {
                result = calculate_ln(arg);
            } else {
                printf("Ошибка: неизвестная функция %s\n", token.value);
                free(values->data);
                free(values);
                exit(1);
            }

            Token result_token = create_token(FUNCTION, "");
            snprintf(result_token.value, sizeof(result_token.value), "%lf", result);
            push(values, result_token);
        }
    }

    double result = atof(pop(values).value);
    free(values->data);
    free(values);
    return result;
}
