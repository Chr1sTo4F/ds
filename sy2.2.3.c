//写代码：定义链式存储的队列（单链表实现）
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} LinkedQueue;

void initQueue(LinkedQueue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

bool isEmpty(LinkedQueue* queue) {
    return queue->front == NULL;
}

void enqueue(LinkedQueue* queue, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(LinkedQueue* queue) {
    if (isEmpty(queue)) {
        printf("队列为空，无法删除元素\n");
        return -1;
    }

    Node* dequeuedNode = queue->front;
    int dequeuedItem = dequeuedNode->data;

    queue->front = queue->front->next;
    free(dequeuedNode);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return dequeuedItem;
}

void display(LinkedQueue* queue) {
    if (isEmpty(queue)) {
        printf("队列为空\n");
        return;
    }

    Node* current = queue->front;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    LinkedQueue queue;
    initQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    display(&queue);  // 输出：1 2 3

    dequeue(&queue);
    display(&queue);  // 输出：2 3

    enqueue(&queue, 4);
    enqueue(&queue, 5);
    display(&queue);  // 输出：2 3 4 5

    return 0;
}