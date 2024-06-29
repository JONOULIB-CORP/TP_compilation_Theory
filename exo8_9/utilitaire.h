#ifndef UTILITAIRE_H
#define UTILITAIRE_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

void enqueue(Queue* q, int data);
int dequeue(Queue* q);
int isQueueEmpty(Queue* q);

void push(Stack* s, int data);
int pop(Stack* s);
int isStackEmpty(Stack* s);

#endif // UTILITAIRE_H
