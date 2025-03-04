#include <stdio.h>

// Function to merge two sorted subarrays in-place
void merge(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1;
    
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            i++;
        } else {
            int temp = arr[j];
            int k = j;
            while (k > i) {  // Shift elements to make space
                arr[k] = arr[k - 1];
                k--;
            }
            arr[i] = temp;

            // Update pointers
            i++;
            mid++;
            j++;
        }
    }
}

// Recursive function for Merge Sort
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        
        mergeSort(arr, low, mid);     // Sort first half
        mergeSort(arr, mid + 1, high); // Sort second half
        
        merge(arr, low, mid, high);    // Merge both halves
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
