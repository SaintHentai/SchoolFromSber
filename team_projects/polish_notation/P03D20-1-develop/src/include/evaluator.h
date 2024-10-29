#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "lexer.h"
#include "stack.h"
// Прототип функции для вычисления выражений в ОПН
double evaluate_rpn(const Token* rpn_tokens, int rpn_count, double x_value);

#endif
