#include "include/stack.h"

#include <stdio.h>
#include <stdlib.h>

Stack* create_stack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (Token*)malloc(sizeof(Token) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push(Stack* stack, Token token) {
    if (stack->top == stack->capacity - 1) {
        printf("Error: stack overflow\n");
        exit(1);
    }
    stack->data[++stack->top] = token;
}

Token pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Error: stack is empty\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

Token peek(Stack* stack) {
    if (stack->top == -1) {
        printf("Error: stack is empty\n");
        exit(1);
    }
    return stack->data[stack->top];
}

int is_empty(Stack* stack) { return stack->top == -1; }
