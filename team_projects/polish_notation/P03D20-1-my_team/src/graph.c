#include "graph.h"

int main() {
    char input_str[STR_MAX] = {'\0'};
    stack* head = NULL;
    if (input(input_str) && checking_brackets(input_str) && parse(input_str, &head)) {
        stack* out_list = get_polish(head);
        stack* out_stack = revers_stack(&out_list);
        double data[HEIGHT];
        double x = 0;
        double dx = 4 * M_PI / (HEIGHT - 1);
        int flag = 1;
        for (int i = 0; i < HEIGHT && flag; i++) {
            data[i] = get_stack_value(out_stack, x, &flag);
            x += dx;
        }
        if (flag) {
            frame_add(data);
        } else {
            printf("n/a");
        }
        destroy_stack(&head);
        destroy_stack(&out_list);
        destroy_stack(&out_stack);
    } else {
        printf("n/a");
    }
    return 0;
}