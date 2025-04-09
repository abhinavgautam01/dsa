#include <stdio.h>
#include <stdlib.h>
void printArray(int arr[], int n){
    for(int i=0; i<n ; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int binarySearch(int arr[], int low, int high, int key){
    if(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]>key){
            return binarySearch(arr, low, mid-1, key);
        }
        return binarySearch(arr, mid+1, high, key);
    }
    return -1;
}

void merge(int arr[], int left, int mid, int right){
    int i, j, k;
    int n1= mid-left+1;
    int n2= right-mid;
    int *L = (int*)malloc(n1*sizeof(int));
    int *R = (int*)malloc(n2*sizeof(int));
    if(L==NULL || R==NULL){
        printf("Memory allocation failed..!");
        exit(1);
    }
    for(i=0; i<n1; i++){
        L[i] = arr[left+i];
    }
    for(j=0; j<n2; j++){
        R[j] = arr[mid+1+j];
    }
    i=0;
    j=0;
    k=left;
    while(i<n1 &&j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}
void mergeSort(int arr[], int left, int right){
    if(left<right){
        int mid = left + (right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i= low-1;
    for(int j= low; j<high; j++){
        if(arr[j]<pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quickSort(int arr[], int left, int right){
    if(left<right){
        int p = partition(arr, left, right);
        quickSort(arr, left, p-1);
        quickSort(arr, p+1, right);
    }
}


// Merge Sort: inPlace 
void inPlaceMerge(int arr[], int start, int mid, int end) {
    int start2 = mid + 1;

    // If already sorted
    if (arr[mid] <= arr[start2])
        return;

    while (start <= mid && start2 <= end) {
        if (arr[start] <= arr[start2]) {
            start++;
        } else {
            int value = arr[start2];
            int index = start2;

            // Shift all elements between arr[start] and arr[start2] right by one
            while (index != start) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[start] = value;

            // Update all pointers
            start++;
            mid++;
            start2++;
        }
    }
}

void mergeSortInPlace(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSortInPlace(arr, l, m);
        mergeSortInPlace(arr, m + 1, r);

        inPlaceMerge(arr, l, m, r);
    }
}
