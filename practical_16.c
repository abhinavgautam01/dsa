// WAP to calculate factorial and to compute the factors of a given no. (i) using recursion, (ii) using iteration.
#include <stdio.h>

// Function prototypes
int factorialRecursion(int n);
int factorialIteration(int n);
void printFactors(int n);

int main() {
    int number;

    // Input from user
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    // Factorial using recursion
    int factRec = factorialRecursion(number);
    printf("Factorial of %d (using recursion) is: %llu\n", number, factRec);

    // Factorial using iteration
    int factIter = factorialIteration(number);
    printf("Factorial of %d (using iteration) is: %llu\n", number, factIter);

    // Print factors
    printf("Factors of %d are: ", number);
    printFactors(number);
    
    return 0;
}

// Function to calculate factorial using recursion
int factorialRecursion(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorialRecursion(n - 1);
}

// Function to calculate factorial using iteration
int factorialIteration(int n) {
    int result = 1;
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
