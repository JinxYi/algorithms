#include <stdio.h>

void swap(int* a, int* b);
void printArray(int *arr, int N);
void heapSort(int *arr, int n);

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);
    // Function call
    heapSort(arr, N);
    printf("Sorted array is\n");
    printArray(arr, N);
    return 0;
}

void heapSort(int *arr, int n) {
    int i;
    for(i=n/2-1; i>=0; i--) { // make the maxifying tree 
        heapify(arr, n, i);
    }
    
    for(i=n-1; i>=0; i--) {
        swap(&arr[0], &arr[i]); // placing largest el to the pos of the rightmost leaf node
        heapify(arr, i, 0); // heapify the array to get root again
    }
}

void heapify(int *arr, int n, int p) {
    int largest = p;
    int left = 2*p+1;
    int right = 2*p+2;
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != p) {
        swap(&arr[p], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *arr, int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}