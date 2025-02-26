#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum stack size

int stack[MAX], top = -1;

// Function to push an element into the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack[++top] = value;
    printf("%d pushed into the stack\n", value);
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow! Nothing to pop\n");
        return -1;
    }
    printf("%d popped from the stack\n", stack[top]);
    return stack[top--];
}

// Function to display the stack
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

// Main function
int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    push(40);
    push(50);
    push(60);
    display();
    return 0;
}
