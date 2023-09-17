#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

// 初始化栈
void initStack(Stack* stack) {
    stack->top = NULL;
}

// 判断栈是否为空
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// 入栈操作
void push(Stack* stack, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
}

// 出栈操作
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    }

    Node* nodeToRemove = stack->top;
    int poppedItem = nodeToRemove->data;
    stack->top = nodeToRemove->next;
    free(nodeToRemove);

    return poppedItem;
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Stack is empty: %s\n", isEmpty(&stack) ? "true" : "false");

    int item = pop(&stack);
    printf("Popped element: %d\n", item);

    return 0;
}