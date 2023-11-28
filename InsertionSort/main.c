#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertionSort(int list[], int n);
void swap(int * list1, int * list2);
void printList(int list[], int n);

int main() {
    int size, x;
    printf("Enter an array size: ");
    scanf("%d", & size);
    printf("Enter max value of record: ");
    scanf("%d", & x);
    int * list = (int * ) malloc(size * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        list[i] = rand() % (x + 1); // generate 0 tp 99
    }
    printf("Unsorted Array: \n");
    printList(list, size);
    InsertionSort(list, size);
    printf("Sorted Array: \n");
    printList(list, size);
    free(list); 
    return 0;
}

// input list is an array of n records
void InsertionSort(int list[], int n) {
    if(n<=1) return;
    for (int i = 1; i < n; i++) // loop starts from 2nd el to the last el in the array
    {
        for (int j = i; j > 0; j--) // compare every element to its previous el
        {
            if (list[j] < list[j - 1]) {
                swap( & list[j], & list[j - 1]);
            }
            else break;
        }
    }
}

void swap(int * list1, int * list2) {
    int temp = *list1;
    *list1 = *list2;
    *list2 = temp;
}

void printList(int list[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}
