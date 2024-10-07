//Radix Sort: Requires separating and sorting negative and non-negative numbers separately.
#include <stdio.h>
#include <stdlib.h>

void countingSortRadix(int arr[], int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};

    if (output == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Count occurrences of each digit
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Cumulative count
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy output back to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(output);
}

void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    // Sort by each digit
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSortRadix(arr, n, exp);
}

void radixSortWithNegatives(int arr[], int n) {
    // Separate negative and non-negative numbers
    int *negatives = (int *)malloc(n * sizeof(int));
    int *nonNegatives = (int *)malloc(n * sizeof(int));
    int negCount = 0, nonNegCount = 0;

    if (negatives == NULL || nonNegatives == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            negatives[negCount++] = -arr[i]; // Store positive equivalent
        } else {
            nonNegatives[nonNegCount++] = arr[i];
        }
    }

    // Sort both parts
    radixSort(nonNegatives, nonNegCount);
    radixSort(negatives, negCount);

    // Combine results: negatives in reverse order followed by non-negatives
    for (int i = 0; i < negCount; i++) {
        arr[i] = -negatives[negCount - 1 - i];
    }
    for (int i = 0; i < nonNegCount; i++) {
        arr[negCount + i] = nonNegatives[i];
    }

    free(negatives);
    free(nonNegatives);
}

// Example usage
int main() {
    int arr[] = {4, -1, 3, 2, -5, 0, -2};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSortWithNegatives(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
