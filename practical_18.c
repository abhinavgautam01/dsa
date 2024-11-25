// WAP to calculate GCD of 2 numbers (i) with recursion (ii) without recursion.
#include <stdio.h>

// Function prototypes
int gcdRecursion(int a, int b);
int gcdIteration(int a, int b);

int main() {
    int num1, num2;

    // Input from user
    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    // Calculate GCD using recursion
    int gcdRec = gcdRecursion(num1, num2);
    printf("GCD of %d and %d (using recursion) is: %d\n", num1, num2, gcdRec);

    // Calculate GCD using iteration
    int gcdIter = gcdIteration(num1, num2);
    printf("GCD of %d and %d (using iteration) is: %d\n", num1, num2, gcdIter);

    return 0;
}

// Function to calculate GCD using recursion
int gcdRecursion(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcdRecursion(b, a % b);
}

// Function to calculate GCD using iteration
int gcdIteration(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
