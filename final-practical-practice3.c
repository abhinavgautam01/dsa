#include <stdio.h>
#include <stdlib.h>

void inputArray(int arr[], int n){
    int i;
    for(int i=0;i<n;i++){
        printf("Enter element %d : ");
        scanf("%d",&arr[i]);
    }
}
void displayArray(int arr[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void swap(int *a, int*b){
    int temp= *a;
    *a=*b;
    *b=temp;
}
void bubbleSort(int arr[], int size){
    int i,j;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-i;j++){
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
    int i,j,minindex;
    for(i=0;i<size-1;i++){
        minindex=i;
        for(j=i+1;j<size;j++){
            if(arr[minindex]>arr[j]){
                minindex=j;
            }
        }
        if(minindex!=0){
            swap(&arr[minindex],&arr[i]);
        }
    }
}

void merge(int arr[], int left, int mid, int right){
    int leftsize=mid-left+1;
    int rightsize=right-mid;
    int *l=(int*)malloc(leftsize*sizeof(int));
    int *r=(int*)malloc(rightsize*sizeof(int));
    if(l==NULL || r==NULL){
        printf("Memory allocation failed..!\n");
        exit(1);
    }
    for(int i=0;i<leftsize;i++){
        l[i]=arr[left+i];
    }
    for(int i=0;i<leftsize;i++){
        r[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=left;
    while(i<leftsize && j<rightsize){
        if(l[i]<=r[j]){
            arr[k]=l[i];
            k++;
            i++;
        }
        else{
            arr[k]=r[j];
            k++;
            j++;
        }
    }
    while(i<leftsize){
        arr[k]=l[i];
        k++;
        i++;
    }
    while(j<rightsize){
        arr[k]=r[j];
        k++;
        j++;
    }
    free(l);
    free(r);
}
void mergeSort(int arr[], int left, int right){
    if(left<right){
        int mid= left+(right-left)/2;
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
    return (i+1);
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
        swap(&arr[i],&arr[largest]);
        heapify(arr, size, largest);
    }
}
void heapsort(int arr[], int size){
    for(int i=(size/2)-1;i>=0;i--){
        heapify(arr, size, i);
    }
    for(int i=size-1;i>=0;i--){
        swap(&arr[i],&arr[0]);
        heapify(arr, i, 0);
    }
}