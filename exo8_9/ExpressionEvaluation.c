#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>
#include "ExpressionEvaluation.h"
#include "utilitaire.h"

void exp_post_fixe_sans_prio(const char* expr, char* result) {
    while (*expr != '\0') {
        if (isdigit(*expr)) {
            // Traitement des nombres à plusieurs chiffres
            while (isdigit(*expr)) {
                *result++ = *expr++;
            }
            *result++ = ' ';
        } else if (*expr == '+' || *expr == '-' || *expr == '*' || *expr == '/') {
            *result++ = *expr++;
            *result++ = ' ';
        } else {
            expr++;
        }
    }
    *result = '\0';
}

int eval_expr_sans_prio(char *expression) {
    int result = 0;
    int current_number = 0;
    char current_operator = '+';

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            current_number = current_number * 10 + (expression[i] - '0');
        } else if (expression[i] == '+' || expression[i] == '*') {
            switch (current_operator) {
                case '+':
                    result += current_number;
                    break;
                case '*':
                    result *= current_number;
                    break;
                default:
                    break;
            }
            current_operator = expression[i];
            current_number = 0;
        }
    }

    // Effectuer la dernière opération
    switch (current_operator) {
        case '+':
            result += current_number;
            break;
        case '*':
            result *= current_number;
            break;
        default:
            break;
    }

    return result;
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return 0;
}

void exp_post_fixe_avec_prio(const char* expr, char* result) {
    Stack stack = {NULL};
    Queue queue = {NULL, NULL};

    while (*expr != '\0') {
        if (isdigit(*expr)) {
            // Traitement des nombres à plusieurs chiffres
            while (isdigit(*expr)) {
                *result++ = *expr++;
            }
            *result++ = ' ';
        } else if (*expr == '+' || *expr == '-' || *expr == '*' || *expr == '/') {
            while (!isStackEmpty(&stack) && precedence(stack.top->data) >= precedence(*expr)) {
                *result++ = pop(&stack);
                *result++ = ' ';
            }
            push(&stack, *expr++);
        } else {
            expr++;
        }
    }

    while (!isStackEmpty(&stack)) {
        *result++ = pop(&stack);
        *result++ = ' ';
    }

    *result = '\0';
}

int evaluate_postfix(const char* expression) {
    Stack stack = {NULL};

    while (*expression != '\0') {
        if (isdigit(*expression)) {
            int num = 0;
            while (isdigit(*expression)) {
                num = num * 10 + (*expression - '0');
                expression++;
            }
            push(&stack, num);
        } else if (*expression == '+' || *expression == '*' || *expression == '-' || *expression == '/') {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (*expression) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Opérateur non supporté.\n");
                    return -1;
            }
            expression++;
        } else {
            expression++;
        }
    }

    return pop(&stack);
}
