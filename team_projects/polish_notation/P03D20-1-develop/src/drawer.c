#include "include/drawer.h"

#include <math.h>
#include <stdio.h>

#define M_PI 3.14159265358979323846 //если мак будет ругаться

void build_graph(const char* expression) {
    int token_count = 0;
    Token* tokens = tokenize(expression, &token_count);

    int rpn_count = 0;
    Token* rpn_tokens = convert_to_rpn(tokens, token_count, &rpn_count);

    double step = (4 * M_PI) / 80;

    char graph[25][80];

    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 80; ++j) {
            graph[i][j] = '.';
        }
    }

    for (int x_pixel = 0; x_pixel < 80; ++x_pixel) {
        double x_value = 0 + x_pixel * step;
        double y_value = evaluate_rpn(rpn_tokens, rpn_count, x_value);

        int y_pixel = (int)((1 - y_value) * (25 - 1) / 2);

        if (y_pixel >= 0 && y_pixel < 25) {
            graph[y_pixel][x_pixel] = '*';
        }
    }

    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 80; ++j) {
            printf("%c", graph[i][j]);
        }
        printf("\n");
    }
}
