#include <math.h>
#include <stdio.h>
#include <string.h>

#include "include/drawer.h"
#include "include/math_ops.h"

void display_menu();
void handle_function_template();
void handle_manual_function_input();
void display_instruction();
void display_rpn_help();
void display_authors();
void main_screen(const char* function_str);

int main() {
    display_menu();
    return 0;
}

void display_menu() {
    int choice = 0;

    while (choice != 5) {
        printf("\n=== Main Menu ===\n");
        printf("1. Function Template Selection\n");
        printf("2. Manual Function Input\n");
        printf("3. Instructions\n");
        printf("4. RPN Help\n");
        printf("5. Exit\n");
        printf("Choose an action: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                handle_function_template();
                break;
            case 2:
                handle_manual_function_input();
                break;
            case 3:
                display_instruction();
                break;
            case 4:
                display_rpn_help();
                break;
            case 5:
                display_authors();
                break;
            default:
                printf("Invalid input. Please choose a correct action.\n");
        }
    }
}

void handle_function_template() {
    int choice;
    printf("\nВыберите шаблон функции:\n");
    printf("1. sin(x)\n");
    printf("2. cos(x)\n");
    printf("3. tan(x)\n");
    printf("4. sqrt(x)\n");
    printf("Выберите шаблон: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            main_screen("sin(x)");
            break;
        case 2:
            main_screen("cos(x)");
            break;
        case 3:
            main_screen("tan(x)");
            break;
        case 4:
            main_screen("sqrt(x)");
            break;
        default:
            printf("Неверный выбор шаблона. Возвращение в главное меню.\n");
            display_menu();
            break;
    }
}

void handle_manual_function_input() {
    int back_to_menu = 0;
    char expression[256];

    while (back_to_menu != 1) {
        printf("\nEnter the expression to plot the graph: ");
        scanf("%255s", expression);
        expression[strcspn(expression, "\n")] = 0;
        printf("Function: %s\n", expression);
        printf("Graph:\n");

        build_graph(expression);
        printf("X Range: [0; 4π], Y Range: [-1; 1]\n");
        printf("Enter 1 to return to the menu: ");
        scanf("%d", &back_to_menu);
    }
}

void display_instruction() {
    printf("\n=== Instructions ===\n");
    printf("1. Select a function template or enter your own function.\n");
    printf("2. After selecting or entering a function, the program will display the graph.\n");
    printf("3. To return to the menu, use the corresponding option.\n");
}

void display_rpn_help() {
    printf("\n=== RPN Help ===\n");
    printf("Reverse Polish Notation (RPN) is used to simplify calculations.\n");
    printf("Example: the expression (2+3)*4 is written in RPN as 2 3 + 4 *\n");
}

void display_authors() {
    printf("\n=== Exit ===\n");
    printf("The program was developed by the following authors:\n");
    printf("1. Nissasyb - Nikolai Yakunin 1\n");
    printf("2. Necromau - Artem Tyutyunik 2\n");
    printf("3. Themissh - Kira Floryu 3\n");
}

void main_screen(const char* function_str) {
    int back_to_menu = 0;

    while (back_to_menu != 1) {
        printf("\n=== Main Screen ===\n");
        printf("Function: %s\n", function_str);
        printf("Graph:\n");
        build_graph(function_str);
        printf("X Range: [0; 4π], Y Range: [-1; 1]\n");
        printf("Enter 1 to return to the menu: ");
        scanf("%d", &back_to_menu);
    }
}
