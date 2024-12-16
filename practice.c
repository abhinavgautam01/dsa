#include <stdio.h>
#include <stdlib.h>
void inputArray(int arr[], int size){
    int i;
    printf("Enter %d elements :\n",size);
    for(i=0;i<size;i++){
        printf("Enter Element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
}
void displayArray(int arr[], int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int linearSearch(int arr[], int size, int key){
    int i;
    for(i=0;i<size;i++){
        if(arr[i]==key){
            return i+1;
        }
    }
    return -1;
}

int binarySearch(int arr[], int low, int high, int key){
    if(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            return binarySearch(arr, low, mid-1, key);
        }
        else{
            return binarySearch(arr, mid+1, high, key);
        }
    }
    return -1;
}

void bubbleSort(int arr[], int size){
    int i,j;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void insertionSort(int arr[], int size){
    int i,j,key;
    for(i=1;i<size;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void selectionSort(int arr[], int size){
    int i,j,minIndex;
    for(i=0;i<size-1;i++){
        minIndex=i;
        for(j=i+1;j<size;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        if(minIndex!=i){
            swap(&arr[i],&arr[minIndex]);
        }
    }
}

void merge(int arr[], int left, int mid, int right){
    int lsize=mid-left+1;
    int rsize=right-mid;
    int *l=(int*)malloc(lsize*sizeof(int));
    int *r=(int*)malloc(rsize*sizeof(int));
    if(l==NULL || r==NULL){
        printf("Memory allocation failed..!");
        exit(1);
    }
    for(int i=0;i<lsize;i++){
        l[i]=arr[left+i];
    }
    for(int i=0;i<rsize;i++){
        r[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=left;
    while(i<lsize && j<rsize){
        if(l[i]<r[j]){
            arr[k]=l[i];
            i++;
            k++;
        }
        else{
            arr[k]=r[j];
            j++;
            k++;
        }
    }
    while(i<lsize){
        arr[k]=l[i];
        i++;
        k++;
    }
    while(j<rsize){
        arr[k]=r[j];
        j++;
        k++;
    }
    free(l);
    free(r);
}
void mergeSort(int arr[], int left, int right){
    if(left<right){
        int mid = left+(right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int left, int right){
    int pivot=arr[right];
    int i=left-1;
    for(int j=left;j<right;j++){
        if(pivot>arr[j]){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[right]);
    return i+1;
}
void quickSort(int arr[], int left, int right){
    if(left<right){
        int q=partition(arr, left, right);
        quickSort(arr, left, q-1);
        quickSort(arr, q+1, right);
    }
}

void heapify(int arr[], int size, int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<size && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<size && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        heapify(arr, size, largest);
    }
}
void heapSort(int arr[], int size){
    for(int i=(size/2)-1;i>=0;i--){
        heapify(arr, size, i);
    }
    for(int i=size-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr, i, 0);
    }
}

