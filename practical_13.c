#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the circular queue

int queue[MAX];  // Array to store the queue elements
int front = -1;  // Front of the queue
int rear = -1;   // Rear of the queue

// Function to check if the queue is full
int isFull() {
    return (rear + 1) % MAX == front;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to enqueue (add) an element to the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty()) {
        front = 0; // First element added
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("Enqueued %d\n", value);
}

// Function to dequeue (remove) an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1; // Indicates an error
    }
    int dequeuedValue = queue[front];
    if (front == rear) {
        // Queue has only one element, reset it
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    printf("Dequeued %d\n", dequeuedValue);
    return dequeuedValue;
}

// Function to display the queue
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
