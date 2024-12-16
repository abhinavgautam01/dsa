#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the queue

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
void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d to queue.\n", data);
        return;
    }
    if (isEmpty()) {
        front = 0; // Set front to 0 if the queue is empty
    }
    rear = (rear + 1) % MAX; // Circular increment
    queue[rear] = data;
    printf("%d enqueued to queue\n", data);
}

// Function to dequeue (remove) an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
        return -1; // Indicates that the queue is empty
    }
    int dequeuedData = queue[front];
    if (front == rear) {
        // Queue is now empty after this dequeue
        front = rear = -1;
    } else {
        front = (front + 1) % MAX; // Circular increment
    }
    printf("%d dequeued from queue\n", dequeuedData);
    return dequeuedData;
}

// Function to display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements:\n");
    int i = front;
    while (1) {
        printf("%d\n", queue[i]);
        if (i == rear) break; // Stop when reaching the rear
        i = (i + 1) % MAX; // Circular increment
    }
}

int main() {
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
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
