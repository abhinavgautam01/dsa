//Counting Sort: Can handle negative values by adjusting the indices.
#include <stdio.h>
#include <stdlib.h>

void countingSortWithNegatives(int arr[], int n) {
    int min = arr[0], max = arr[0];

    // Find min and max values
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int range = max - min + 1;
    int *count = (int *)calloc(range, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    if (count == NULL || output == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Count occurrences of each value
    for (int i = 0; i < n; i++)
        count[arr[i] - min]++;

    // Cumulative count
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    // Copy output back to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(count);
    free(output);
}

// Example usage
int main() {
    int arr[] = {4, -1, 3, 2, -5, 0, -2};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSortWithNegatives(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
