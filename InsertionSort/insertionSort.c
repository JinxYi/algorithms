#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int n);
void insertionSort(int arr[], int n);
void swap(int * item1, int * item2);

int main()
{
    int arr[] = {5, 2, 7, 3, 7};
    int arraySize = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, arraySize);
    printArray(arr, arraySize);
    return 0;
}

void insertionSort(int arr[], int n)
{
    if(n<=1) return;
    for (int i = 1; i < n; i++) // i here ranges from 1 to n-1
    {
        for(int j=i; j>0; j--) // j here ranges from n to 0 for each 1
        {
            if (arr[j] < arr[j-1]) {
                swap(&arr[j], &arr[j-1]);
            }
        }
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void swap(int * item1, int * item2) {
    int temp = * item1;
    * item1 = * item2;
    * item2 = temp;
}