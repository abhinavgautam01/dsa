#include <stdio.h>
#include <stdlib.h>
void countingSort(int arr[], int n, int range) {
    int *count = (int *)calloc(range + 1, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));
    if (count == NULL || output == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    for (int i = 1; i <= range; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    free(count);
    free(output);
}
void countingSortRadix(int arr[], int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};
    if (output == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    free(output);
}
void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSortRadix(arr, n, exp);
}
int main() {
    int n;
    char choice;
    do {
        printf("Enter the number of elements: ");
        scanf("%d", &n);
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        printf("Enter the elements:\n");
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        printf("Choose sorting method:\n");
        printf("1. Counting Sort\n");
        printf("2. Radix Sort\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1': {
                int max = arr[0];
                for (int i = 1; i < n; i++)
                    if (arr[i] > max)
                        max = arr[i];
                countingSort(arr, n, max);
                printf("Sorted array using Counting Sort:\n");
                break;
            }
            case '2':
                radixSort(arr, n);
                printf("Sorted array using Radix Sort:\n");
                break;
            default:
                printf("Invalid choice!\n");
                free(arr);
                continue;
        }
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
        free(arr);
        printf("Do you want to sort again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    return 0;
}