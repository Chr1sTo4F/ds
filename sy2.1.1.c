#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push element.\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    }
    int poppedItem = stack->data[stack->top];
    stack->top--;
    return poppedItem;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek element.\n");
        return -1;
    }
    return stack->data[stack->top];
}

int size(Stack* stack) {
    return stack->top + 1;
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Stack is empty: %s\n", isEmpty(&stack) ? "true" : "false");
    printf("Stack size: %d\n", size(&stack));
    printf("Stack top element: %d\n", peek(&stack));

    int item = pop(&stack);
    printf("Popped element: %d\n", item);

    printf("Stack top element: %d\n", peek(&stack));
    printf("Stack size: %d\n", size(&stack));

    return 0;
}