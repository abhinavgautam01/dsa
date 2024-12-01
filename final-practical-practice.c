#include <stdio.h>
#include <stdlib.h>
void inputArray(int arr[],int size){
    int i;
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

void linearSearch(int arr[], int size, int key){
    int i,flag=0;
    for(i=0;i<size;i++){
        if(arr[i]==key){
            printf("Element found at position %d and at index %d of the array.\n",i+1,i);
            flag+=1;
        }
    }
    if(flag==0){
        printf("Element not found..!\n");
    }
    else{
        printf("%d is found %d times in the given array.\n",key,flag);
    }
}

void swap(int *a, int *b){
    int temp=*a;
        *a=*b;
        *b=temp;
}

void bubblesSort(int arr[], int size){
    int i,j,swapped;
    for ( i = 0; i < size-1; i++)
    {
        swapped=0;
        for ( j = 0; j < size-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                swap(&arr[j+1],&arr[j]);
                swapped=1;
            }
        }
        if(swapped == 0)
            break;
    } 
}
void m(int arr[], int left, int mid, int right){
    int lsize=mid-left+1;
    int rsize=right-mid;
    int *l=(int*)malloc(lsize*sizeof(int));
    int *r=(int*)malloc(rsize*sizeof(int));
    for(int i=0;i<lsize;i++){
        l[i]=arr[left+i];
    }
    for(int i=0;i<rsize;i++){
        r[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=left;
    while(i<lsize && j<rsize){
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
    while(i<lsize){
        arr[k]=l[i];
        k++;
        i++;
    }
    while(j<rsize){
        arr[k]=r[j];
        k++;
        j++;
    }
}

void merge(int arr[], int left, int mid, int right){
    int leftSize = mid-left+1;
    int rightSize = right-mid;

    int *L = (int *)malloc(leftSize * sizeof(int));
    int *R = (int *)malloc(rightSize * sizeof(int));
    if(L==NULL || R==NULL){
        printf("Memory allocation failed..!");
        exit(1);
    }
    for(int i =0; i<leftSize;i++){
        L[i]=arr[left+i];
    }
    for(int j =0; j<rightSize;j++){
        R[j]=arr[mid+1+j];
    }
    int i=0,j=0,k=left;
    while (i < leftSize && j < rightSize) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            k++;
            i++;
        } else {
            arr[k] = R[j];
            k++;
            j++;
        }
    }
    // Copy any remaining elements of L[], if any
    while (i < leftSize) {
        arr[k] = L[i];
        k++;
        i++;
    }
    // Copy any remaining elements of R[], if any
    while (j < rightSize) {
        arr[k] = R[j];
        k++;
        j++;
    }
    // Free dynamically allocated memory
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right){
    if(left<right){
        int mid = left + (right-left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
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
            if(arr[minIndex]>arr[j]){
                minIndex=j;
            }
        }
        if(minIndex!=i){
            swap(&arr[minIndex],&arr[i]);
        }
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

int partition(int arr[], int left, int right){
    int pivot= arr[right];
    int i=(left-1);
    for(int j=left;j<=right-1;j++){
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

int main(){
    int size,target,result;
    printf("Enter number of elements for your array: ");
    scanf("%d",&size);
    int arr[size];
    inputArray(arr, size);
    printf("Entered Elements:\n");
    displayArray(arr, size);
    printf("Elements after sorting:\n");
    bubblesSort(arr,size);
    displayArray(arr, size);
    printf("Enter element to be searched in the array: ");
    scanf("%d",&target);
    // linearSearch(arr,size,target);

    result=binarySearch(arr,0,size-1,target);
    if(result!=-1){
        printf("Element found at position %d and at index %d in the given array.\n",result+1,result);
    }
    else{
        printf("Element not found..!\n");
    }
}