#include <stdio.h>
#include <stdlib.h>
void merge_sort(int arr[], int left, int right);
void quick_sort(int arr[], int low, int high);
void heap_sort(int arr[], int n);
void heapify(int arr[], int n, int i);
void print_array(int arr[], int n);
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}
void heap_sort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // One by one extract elements from heap    
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    char choice;
    do {
        int n;
        printf("Enter the number of elements: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter the elements:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        char sort_choice;
        input:  // Label for the goto statement
        printf("\nChoose the sorting method:\n");
        printf("1. Merge Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Heap Sort\n");
        printf("4. Exit\n");  // Exit option added
        printf("Enter your choice (1, 2, 3, or 4): ");
        scanf(" %c", &sort_choice);
        switch (sort_choice) {
            case '1':
                merge_sort(arr, 0, n - 1);
                printf("Sorted array using Merge Sort: ");
                break;
            case '2':
                quick_sort(arr, 0, n - 1);
                printf("Sorted array using Quick Sort: ");
                break;
            case '3':
                heap_sort(arr, n);
                printf("Sorted array using Heap Sort: ");
                break;
            case '4':
                printf("Exiting the program. Goodbye!\n");
                return 0;  // Exit the program
            default:
                printf("Invalid choice! Please try again.\n");
                goto input;  // Go back to the sorting method menu
        }
        print_array(arr, n);
        printf("Do you want to sort again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    return 0;
}