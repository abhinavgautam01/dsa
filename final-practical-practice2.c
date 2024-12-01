#include <stdio.h>
#include <stdlib.h>
void inputArray(int arr[], int size){
    int i;
    for(i=0;i<size;i++){
        printf("Enter element %d : ",i+1);
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

void linearSearch(int arr[], int size, int key){
    int i,flag=0;
    for(i=0;i<size;i++){
        if(arr[i]==key){
            printf("Element found at position %d and at index %d in the given array\n",i+1,i);
            flag++;
        }
    }
    if(flag!=0){
        printf("%d found %d times in the array.\n",key,flag);
    }
    else{
        printf("Element not found..!\n");
    }
}

int binarySearch(int arr[], int low, int high, int key){
    if(low>high){
        return -1;
    }
    int mid=low+(high-low)/2;
    if(arr[mid]==key){
        return mid;
    }
    else if(arr[mid]>key){
        return binarySearch(arr, low, mid-1, key);
    }
    else{
        return binarySearch(arr, mid+1, high, key);
    }
    return -1;
}

void bubbleSort(int arr[], int size){
    int i,j,swapped=0;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swapped=1;
            }
        }
        if(swapped==0){
            break;
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

void selectionSort(int arr[],int size){
    int i,j,minIndex;
    for(i=0;i<size-1;i++){
        minIndex=i;
        for(j=i+1;j<size;j++){
            if(arr[minIndex]>arr[j]){
                minIndex=j;
            }
        }
        if(minIndex!=i){
            swap(&arr[i],&arr[minIndex]);
        }
    }
}

void merge(int arr[], int left, int mid, int right){
    int leftsize=mid-left+1;
    int rightsize=right-mid;
    int *l=(int*)malloc(leftsize*sizeof(int));
    int *r=(int*)malloc(rightsize*sizeof(int));
    if(l==NULL && r==NULL){
        printf("memory allocation failed..!");
        exit(1);
    }
    for(int i=0; i<leftsize;i++){
        l[i]=arr[left+i];
    }
    for(int i=0; i<leftsize;i++){
        r[i]=arr[mid+1+i];
    }
    int i=0, j=0, k=left;
    while(i<leftsize && j < rightsize){
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
        int mid = left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr, left , mid , right);
    }
}

int partition(int arr[], int left, int right){
    int pivot=arr[right];
    int i=(left-1);
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
        int q = partition(arr, left, right);
        quickSort(arr, left, q-1);
        quickSort(arr, q+1, right);
    }
}

void heapify(int arr[], int size, int i){
    int largest= i;
    int left=2*i+1;
    int right= 2*i+2;
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
        swap(&arr[i],&arr[0]);
        heapify(arr, i, 0);
    }
}


int main(){
    int n,key;
    printf("enter size of your array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter your elements : \n");
    inputArray(arr,n);
    printf("entered elements :\n");
    displayArray(arr, n);


    printf("Element after sorting:\n");
    // bubbleSort(arr,n);
    // insertionSort(arr,n);
    // selectionSort(arr,n);
    // mergeSort(arr,0,n-1);
    quickSort(arr, 0, n-1);
    displayArray(arr,n);


    printf("Enter your element to be searched in the array: ");
    scanf("%d",&key);

    int result = binarySearch(arr, 0, n-1, key);

    if(result!=-1){
        printf("Element found at position %d and at index %d in the given array.\n",result+1,result);
    }
    else{
        printf("Element not found in your given array...!\n");
    }

    return 0;
}