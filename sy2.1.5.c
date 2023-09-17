#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* bottom;  // 栈底指针
    Node* top;     // 栈顶指针
    int maxSize;   // 栈的最大容量
    int size;      // 栈的当前大小
} Stack;

// 初始化栈
void initStack(Stack* stack, int maxSize) {
    stack->bottom = NULL;
    stack->top = NULL;
    stack->maxSize = maxSize;
    stack->size = 0;
}

// 判断栈是否为空
int isEmpty(Stack* stack) {
    return stack->size == 0;
}

// 判断栈是否已满
int isFull(Stack* stack) {
    return stack->size == stack->maxSize;
}

// 入栈操作
void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push element.\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;

    if (isEmpty(stack)) {
        stack->bottom = newNode;
        stack->top = newNode;
    } else {
        stack->top->next = newNode;
        stack->top = newNode;
    }

    stack->size++;
}

// 出栈操作
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    }

    Node* nodeToRemove = stack->top;
    int poppedItem = nodeToRemove->data;

    if (stack->size == 1) {
        stack->bottom = NULL;
        stack->top = NULL;
    } else {
        Node* currentNode = stack->bottom;
        while (currentNode->next != stack->top) {
            currentNode = currentNode->next;
        }
        currentNode->next = NULL;
        stack->top = currentNode;
    }

    free(nodeToRemove);
    stack->size--;

    return poppedItem;
}

int main() {
    Stack stack;
    initStack(&stack, 5);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Stack is empty: %s\n", isEmpty(&stack) ? "true" : "false");
    printf("Stack is full: %s\n", isFull(&stack) ? "true" : "false");

    int item = pop(&stack);
    printf("Popped element: %d\n", item);

    return 0;
}