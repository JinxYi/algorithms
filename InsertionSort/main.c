#include <stdio.h>

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
    for (int i = 0; i < size; i++) {
        list[i] = rand() % (x + 1); // generate 0 tp 99
    }
    InsertionSort(list, size);
    printList(list, size);
    return 0;
}

void InsertionSort(int list[], int n) {
    // input list is an array of n records
    // we assume n>1
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
    int temp = * list1;
    * list1 = * list2;
    * list2 = temp;
}

void printList(int list[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}
