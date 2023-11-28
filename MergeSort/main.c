#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void mergeSort(int *list, int l, int r);
void merge(int *list, int l, int m, int r);
void printList(int *list, int size);

int main()
{
    int listSize, x;
    printf("Enter an array size: ");
    scanf("%d", &listSize);
    printf("Enter max value of record: ");
    scanf("%d", &x);

    srand(time(NULL));
    int *list = (int *) malloc(listSize * sizeof(int));
    for (int i = 0; i < listSize; i++)
    {
        list[i] = rand() % (x + 1); // generate 0 to x
    }
    printf("Unsorted Array: \n");
    printList(list, listSize);
    mergeSort(list, 0, listSize-1);
    printf("Sorted Array: \n");
    printList(list, listSize);
    free(list);
    return 0;
}

void mergeSort(int *list, int l, int r)
{
    if (r <= l)
        return; // Nothing to sort
    int m = l + (r - l) / 2;

    // Sort first and second halves
    mergeSort(list, l, m);
    mergeSort(list, m + 1, r);

    merge(list, l, m, r);
}

void merge(int *list, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        L[i] = list[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = list[m + 1 + j];
    }

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            list[k] = L[i];
            i++;
        } else {
            list[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements 
    while (i < n1) {
        list[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        list[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void printList(int *list, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(list + i));
    }
    printf("\n");
}
