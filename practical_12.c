// Perform Queue operations using Array implementation.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the queue

// Define the structure for the queue
struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

// Function to initialize the queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear + 1) % MAX == queue->front;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to enqueue (add) an element to the queue
void enqueue(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue Overflow! Cannot enqueue %d to queue.\n", data);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0; // Set front to 0 if the queue is empty
    }
    queue->rear = (queue->rear + 1) % MAX; // Circular increment
    queue->arr[queue->rear] = data;
    printf("%d enqueued to queue\n", data);
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
        return -1; // Indicates that the queue is empty
    }
    int dequeuedData = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        // Queue is now empty after this dequeue
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX; // Circular increment
    }
    printf("%d dequeued from queue\n", dequeuedData);
    return dequeuedData;
}

// Function to display the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements:\n");
    int i = queue->front;
    while (1) {
        printf("%d\n", queue->arr[i]);
        if (i == queue->rear) break; // Stop when reaching the rear
        i = (i + 1) % MAX; // Circular increment
    }
}

int main() {
    struct Queue* queue = createQueue();
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                free(queue); // Clean up the queue memory
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
