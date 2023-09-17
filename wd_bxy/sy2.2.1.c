//写代码：定义顺序存储的队列（数组实现），要求数组空间可以被循环利用
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

typedef struct {
    int queue[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

void initQueue(CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(CircularQueue *queue) {
    return queue->front == -1 && queue->rear == -1;
}

bool isFull(CircularQueue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(CircularQueue *queue, int item) {
    if (isFull(queue)) {
        printf("队列已满，无法插入新元素\n");
    } else if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
        queue->queue[queue->rear] = item;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->queue[queue->rear] = item;
    }
}

int dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("队列为空，无法删除元素\n");
        return -1;
    } else if (queue->front == queue->rear) {
        int dequeuedItem = queue->queue[queue->front];
        queue->front = -1;
        queue->rear = -1;
        return dequeuedItem;
    } else {
        int dequeuedItem = queue->queue[queue->front];
        queue->front = (queue->front + 1) % MAX_SIZE;
        return dequeuedItem;
    }
}

void display(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("队列为空\n");
    } else {
        int current = queue->front;
        while (current != queue->rear) {
            printf("%d ", queue->queue[current]);
            current = (current + 1) % MAX_SIZE;
        }
        printf("%d\n", queue->queue[queue->rear]);
    }
}

int main() {
    CircularQueue queue;
    initQueue(&queue);
    
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    display(&queue);  // 输出：1 2 3 4 5
    
    dequeue(&queue);
    dequeue(&queue);
    display(&queue);  // 输出：3 4 5
    
    enqueue(&queue, 6);
    enqueue(&queue, 7);
    display(&queue);  // 输出：3 4 5 6 7
    
    return 0;
}