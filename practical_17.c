// WAP to display Fibonacci series (i) using recursion, (ii) using iteration.
#include <stdio.h>

// Function prototypes
void fibonacciRecursion(int n);
void fibonacciIteration(int n);
int fibonacci(int n);

int main() {
    int n;

    // Input from user
    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    printf("Fibonacci Series using recursion:\n");
    fibonacciRecursion(n);

    printf("\nFibonacci Series using iteration:\n");
    fibonacciIteration(n);

    return 0;
}

// Function to display Fibonacci series using recursion
void fibonacciRecursion(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Recursive function to calculate nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to display Fibonacci series using iteration
void fibonacciIteration(int n) {
    int a = 0, b = 1, next;
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d ", a);
            continue;
        }
        if (i == 1) {
            printf("%d ", b);
            continue;
        }
        next = a + b;
        a = b;
        b = next;
        printf("%d ", next);
    }
    printf("\n");
}
