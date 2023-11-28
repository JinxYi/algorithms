#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int array[], int low, int high);
int partition(int array[], int low, int high);
void swap(int *a, int *b);
void printArray(int array[], int size);

int main() {
    int n, x;
    printf("Enter an array size: ");
    scanf("%d", &n);
    printf("Enter max value of record: ");
    scanf("%d", &x);

    srand(time(NULL));
    int *data = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        data[i] = rand() % (x + 1); // generate 0 to x
    }

    printf("Unsorted Array: \n");
    printArray(data, n);

    quickSort(data, 0, n - 1);

    printf("Sorted array: \n");
    printArray(data, n);
}

void quickSort(int array[], int low, int high) {
    if(low>=high) return;
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pivot = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pivot - 1);

    // recursive call on the right of pivot
    quickSort(array, pivot + 1, high);
}

// partition orders the array such that every element to the left of the pivot
// is smaller than every element to the right of the pivot
int partition(int array[], int low, int high) {
    int i, last_small, pivot, mid;

    mid = (low + high) / 2;
    // moving to make it easier to increment
    swap(&array[low], &array[mid]);
    // pivot becomes mid
    pivot = array[low];

    last_small = low; // pointer index containing the tail element of left subarray

    // traverse each element of the array (excluding pivot)
    // compare them with the pivot
    for (i = low + 1; i <= high; i++) {
        if (array[i] < pivot) {
            last_small++;
            swap(&array[last_small], &array[i]);
        }
    }

    // swap the pivot element with the greater element at i
    swap(&array[last_small], &array[low]);

    // return the partition point
    return last_small;
}

// function to swap elements
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// function to print array elements
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}