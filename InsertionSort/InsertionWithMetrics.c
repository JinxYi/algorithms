#include <stdio.h>

#include <windows.h>

void InsertionSort(int list[], int n);
void swap(int * list1, int * list2);
void printList(int list[], int n);

int main() {
    LARGE_INTEGER pc_start, pc_end, CPU_frequency;
    QueryPerformanceFrequency( & CPU_frequency);
    int size, x;
    printf("Enter an array size: ");
    scanf("%d", & size);
    printf("Enter max value of record: ");
    scanf("%d", & x);
    int * list = (int * ) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        list[i] = rand() % (x + 1); // generate 0 tp 99
    }
//    printList(list, size);

    QueryPerformanceCounter( & pc_start);
    InsertionSort(list, size);
    QueryPerformanceCounter( & pc_end);
//    printList(list, size);
    double time_taken = (double)((double)(pc_end.QuadPart - pc_start.QuadPart) / (double) CPU_frequency.QuadPart) * 1000;
    printf("Time taken in milliseconds: %f \n", time_taken);
    return 0;
}

void InsertionSort(int list[], int n) {
    //input list is an array of n records
    //we assume n>1
    int compares = 0, totalCompares = 0;
    int swaps = 0, totalSwaps = 0;

    for (int i = 1; i < n; i++) // loop starts from 2nd el to the last el in the array
    {
        compares = swaps = 0;
        for (int j = i; j > 0; j--) // compare every element to its previous el
        {
            compares++;
            totalCompares++;
            if (list[j] < list[j - 1]) {
                swap( & list[j], & list[j - 1]);
                swaps++;
                totalSwaps++;
            } else break;
        }
    }
    printf("Total compares: %d, Total swaps: %d\n", totalCompares, totalSwaps);
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
