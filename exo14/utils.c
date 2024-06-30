#include "utils.h"
#include <stdlib.h>

void push(StackNode **stack, int data) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = *stack;
    *stack = newNode;
}

int pop(StackNode **stack) {
    if (*stack == NULL) {
        return -1; // Or handle error appropriately
    }
    int data = (*stack)->data;
    StackNode *temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return data;
}

int peek(StackNode *stack) {
    if (stack == NULL) {
        return -1; // Or handle error appropriately
    }
    return stack->data;
}

int isEmpty(StackNode *stack) {
    return stack == NULL;
}
