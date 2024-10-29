#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "stack.h"

Token* convert_to_rpn(const Token* tokens, int token_count, int* rpn_count);

#endif
