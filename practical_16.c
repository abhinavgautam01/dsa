#include <stdio.h>

// Function prototypes
unsigned long long factorialRecursion(int n);
unsigned long long factorialIteration(int n);
void printFactors(int n);

int main() {
    int number;

    // Input from user
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    // Factorial using recursion
    unsigned long long factRec = factorialRecursion(number);
    printf("Factorial of %d (using recursion) is: %llu\n", number, factRec);

    // Factorial using iteration
    unsigned long long factIter = factorialIteration(number);
    printf("Factorial of %d (using iteration) is: %llu\n", number, factIter);

    // Print factors
    printf("Factors of %d are: ", number);
    printFactors(number);
    
    return 0;
}

// Function to calculate factorial using recursion
unsigned long long factorialRecursion(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorialRecursion(n - 1);
}

// Function to calculate factorial using iteration
unsigned long long factorialIteration(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to print factors of a given number
void printFactors(int n) {
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
