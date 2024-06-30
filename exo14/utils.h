#ifndef UTILS_H
#define UTILS_H

typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

void push(StackNode **stack, int data);
int pop(StackNode **stack);
int peek(StackNode *stack);
int isEmpty(StackNode *stack);

#endif
