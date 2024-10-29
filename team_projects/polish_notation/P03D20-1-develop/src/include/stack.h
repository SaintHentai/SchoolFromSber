#ifndef STACK_H
#define STACK_H

#include "lexer.h"

typedef struct {
    Token* data;
    int top;
    int capacity;
} Stack;

Stack* create_stack(int capacity);
void push(Stack* stack, Token token);
Token pop(Stack* stack);
Token peek(Stack* stack);
int is_empty(Stack* stack);

#endif
