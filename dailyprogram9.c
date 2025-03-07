#include <stdio.h>
#include <limits.h>

// Function to find the maximum sum subarray
int kadane(int arr[], int n) {
    int max_sum = INT_MIN; // Stores the maximum sum found
    int current_sum = 0;   // Stores the current sum

    for (int i = 0; i < n; i++) {
        current_sum += arr[i];

        if (current_sum > max_sum)
            max_sum = current_sum; // Update max sum if current sum is greater

        if (current_sum < 0)
            current_sum = 0; // Reset current sum if it becomes negative
    }
    
    return max_sum;
}

// Main function
int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_sum = kadane(arr, n);

    printf("Maximum Sum Subarray: %d\n", max_sum);
    return 0;
}
