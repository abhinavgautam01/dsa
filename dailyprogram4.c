#include <stdio.h>
#define MAX 100

// Queue structure
typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

// Function to initialize queue
void init(Queue *q) {
    q->front = q->rear = -1;
}

// Function to check if queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Function to check if queue is full
int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Function to enqueue an element
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(q))
        q->front = 0;
    q->arr[++q->rear] = value;
}

// Function to dequeue an element
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1; // Reset queue
    else
        q->front++;
    return item;
}

// Function to peek at the front element
int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

int main() {
    Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Front element: %d\n", peek(&q));
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));

    return 0;
}
