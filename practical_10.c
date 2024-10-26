#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the stack

// Define the structure for the stack
struct Stack {
    int top;
    int arr[MAX];
};

// Function to initialize the stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1; // Stack is initially empty
    return stack;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d onto stack.\n", data);
        return;
    }
    stack->arr[++stack->top] = data;
    printf("%d pushed onto stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1; // Indicates that the stack is empty
    }
    return stack->arr[stack->top--];
}

// Function to peek at the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! No top element.\n");
        return -1; // Indicates that the stack is empty
    }
    return stack->arr[stack->top];
}

// Function to display the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->arr[i]);
    }
}

int main() {
    struct Stack* stack = createStack();
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &data);
                push(stack, data);
                break;
            case 2:
                data = pop(stack);
                if (data != -1) {
                    printf("%d popped from stack\n", data);
                }
                break;
            case 3:
                printf("Top element is %d\n", peek(stack));
                break;
            case 4:
                display(stack);
                break;
            case 5:
                free(stack); // Clean up the stack memory
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
