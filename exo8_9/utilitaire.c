#include <stdio.h>
#include <stdlib.h>
#include "utilitaire.h"

// Queue functions
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear) {
        q->rear->next = newNode;
    } else {
        q->front = newNode;
    }
    q->rear = newNode;
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (!q->front) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

// Stack functions
void push(Stack* s, int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    if (isStackEmpty(s)) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    StackNode* temp = s->top;
    int data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

int isStackEmpty(Stack* s) {
    return s->top == NULL;
}
