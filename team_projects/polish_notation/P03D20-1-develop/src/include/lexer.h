#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

typedef enum TokenTypeEnum { NUMBER, OPERATOR, FUNCTION, VARIABLE, LEFT_PAREN, RIGHT_PAREN } TokenType;

typedef struct {
    TokenType type;
    char value[32];  // Строковое представление токена
} Token;

// Прототип функции лексического анализа
Token* tokenize(const char* expression, int* token_count);
Token create_token(TokenType type, const char* value);

#endif
