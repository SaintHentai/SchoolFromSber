#include "include/parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/stack.h"

int get_operator_precedence(char operator) {
    switch (operator) {
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

int is_right_associative(char operator) { return operator== '^'; }

Token* convert_to_rpn(const Token* tokens, int token_count, int* rpn_count) {
    static Token rpn[MAX_TOKENS];
    int index = 0;

    Stack* operators = create_stack(MAX_TOKENS);

    for (int i = 0; i < token_count; ++i) {
        Token token = tokens[i];

        if (token.type == NUMBER || token.type == VARIABLE) {
            rpn[index++] = token;
        } else if (token.type == FUNCTION) {
            push(operators, token);
        } else if (token.type == OPERATOR) {
            while (!is_empty(operators) &&
                   get_operator_precedence(peek(operators).value[0]) >=
                       get_operator_precedence(token.value[0]) &&
                   !is_right_associative(token.value[0])) {
                rpn[index++] = pop(operators);
            }
            push(operators, token);
        } else if (token.type == LEFT_PAREN) {
            push(operators, token);
        } else if (token.type == RIGHT_PAREN) {
            while (!is_empty(operators) && peek(operators).type != LEFT_PAREN) {
                rpn[index++] = pop(operators);
            }
            if (is_empty(operators)) {
                printf("Ошибка: несоответствие скобок\n");
                free(operators->data);
                free(operators);
                exit(1);
            }
            pop(operators);

            if (!is_empty(operators) && peek(operators).type == FUNCTION) {
                rpn[index++] = pop(operators);
            }
        }
    }

    while (!is_empty(operators)) {
        Token op = pop(operators);
        if (op.type == LEFT_PAREN || op.type == RIGHT_PAREN) {
            printf("Ошибка: несоответствие скобок\n");
            free(operators->data);
            free(operators);
            exit(1);
        }
        rpn[index++] = op;
    }

    free(operators->data);
    free(operators);

    *rpn_count = index;
    return rpn;
}
