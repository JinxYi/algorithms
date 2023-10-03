#include <stdio.h>

void quickSort(int array[], int low, int high);
int partition(int array[], int low, int high);
void swap(int *a, int *b);
void printArray(int array[], int size);

int main() {
    int data[] = {8, 7, 2, 1, 0, 9, 6};

    int n = sizeof(data) / sizeof(data[0]);

    printf("Unsorted Array\n");
    printArray(data, n);

    // perform quicksort on data
    quickSort(data, 0, n - 1);

    printf("Sorted array in ascending order: \n");
    printArray(data, n);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
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

    // traverse each element of the array
    // compare them with the pivot
    for (i = low + 1; i <= high; i++) {
        if (array[i] <= pivot) {
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