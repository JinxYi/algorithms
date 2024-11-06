# SC2001 Algorithm Design & Analysis

Subject: Computing
Year/Semester: 21

**Table of Contents**

# Chapter 2: Insertion Sort

![DSAlgorithmGuide.gif](SC2001%20Algorithm%20Design%20&%20Analysis%204d954cb661cb420893d76315df35b941/DSAlgorithmGuide.gif)

- Incremental approach
- **In-place sort**: the original unsorted set and the final ordered list stays in the same place. Only the elements’ places are swapped and no new elements are added to the list. This usually saves money but can my time-consuming.
- During sorting, the array contains sorted subset on the left and unsorted portion on the right

```c
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
```

- Best case: 1 key comparison per iteration
    - e.g. when the array is already sorted, only 1 comparison for each record. thus total is n-1 (index 1 to n)
    - total: n-1 = Θ(n)
- Worst case: i key comparisons for the ith iteration
    - e.g. when the array is sorted reversely, each record at index i will have have i comparisons. therefore the summation of the index i (which takes on the value of 0 to n-1) will be the following (using the arithmetic sequence):
        - Total = 1 + 2 + 3 + … + (n-1) = $\frac{(n-1)n}2$
    - Θ($n^2$)
- Average case: the ith iteration may have 1, 2, …, i key comparisons, each with 1/i chance
    - each record at index i has an average of (sum of all possible no. of compares [1, i]) divide by number of records i
    - average case = summation of all average cases for each record
    - when we sum up the n-1 iterations, we get Θ($n^2$)
    
    ![Untitled](SC2001%20Algorithm%20Design%20&%20Analysis%204d954cb661cb420893d76315df35b941/Untitled.png)
    
- Strengths
    - Good when unordered list is almost sorted
    - Minimum time needed to verify if list is sorted
    - no movement of data needed if linking is used
- Weakness
    - inserted entry may not be in its final position
    - every new insertion requires some movements for inserted entries in ordered list
    - if data is big, swapping will be very expensive
    - Less suitable with contiguous storage implementation (more suitable for list and arrays)

# Chapter 3: Merge Sort

- recursive function/divide and conquer approach
- merge sort is often used in databases where the data are connected as lists

```c
void mergeSort(LinkedList *ll)
{
    if (ll->size <= 1) return; // Nothing to sort
    
    LinkedList left, right;
    split(ll, &left, &right);

    // Recursively sort both halves
    mergeSort(&left);
    mergeSort(&right);

    // Merge the sorted halves
    merge(ll, &left, &right);
}

void merge(LinkedList *ll, LinkedList *left, LinkedList *right)
{
    ListNode *leftPtr = left->head;
    ListNode *rightPtr = right->head;
    ll->head = NULL;
    ListNode *current = NULL;

    while (leftPtr != NULL && rightPtr != NULL) {
        if (leftPtr->item <= rightPtr->item) {
            if (current == NULL) {
                current = leftPtr;
                ll->head = current;
            } else {
                current->next = leftPtr;
                current = current->next;
            }
            leftPtr = leftPtr->next;
        } else {
            if (current == NULL) {
                current = rightPtr;
                ll->head = current;
            } else {
                current->next = rightPtr;
                current = current->next;
            }
            rightPtr = rightPtr->next;
        }
    }

    if (leftPtr != NULL) {
        current->next = leftPtr;
    }

    if (rightPtr != NULL) {
        current->next = rightPtr;
    }

    // Update the size of the merged list
    ll->size = left->size + right->size;
}
```

- `mergeSort()` is recursive
    - mergeSort() function recursively splits the array into 2 equal(ish) sub-arrays
    - W(n/2)
- `merge()` is incremental
    - worst case is n-1, where all elements from left and right sublist are compared.
    - best case is when elements in the one list are all smaller than the other: n/2 comparisons
- strengths
    - Simple and good runtime behavior
    - Easy to implement when using linked list
- Weaknesses
    - Difficult to implement for contiguous data storage such as array without auxiliary storage (requires data movements during merging)
    
    ![Untitled](SC2001%20Algorithm%20Design%20&%20Analysis%204d954cb661cb420893d76315df35b941/Untitled%201.png)
    

# Chapter 4: Quick Sort

- fastest general purpose in-memory sorting algorithm in the average case
- recursive approach
- main idea
    - select an element in the array to be a pivot
    - partition list into two sublists with respect to pivot such that all elements in the left sublist are less than pivot while all element s in the right sublist are greater than or equal to pivot
        - recursively partition until input list has one or zero elements
- best case O($n log n$)
    - happens when pivot happens to divide the array into 2 equal lengths at every partition
    
    ![Untitled](SC2001%20Algorithm%20Design%20&%20Analysis%204d954cb661cb420893d76315df35b941/Untitled%202.png)
    
- worst case O($n^2$)
    
    ![Untitled](SC2001%20Algorithm%20Design%20&%20Analysis%204d954cb661cb420893d76315df35b941/Untitled%203.png)
    
- choosing the pivot is the core of quicksort
- Strengths
    - Fast on average
    - no merging required
    - Best case occurs when pivot always splits array into equal halves
- Weaknesses
    - Poor performance when pivot does not split the array evenly
    - Quicksort also performs badly when the size of list to be sorted is small
    - If more work is done to select pivot carefully, the bad effects can be reduced

# Chapter 5: Heap Sort

- Heap data structure
    - Heap data structure is implemented breadth first from left to right, then top to bottom
    - Heap can be stored as array or tree
    - Parent (i): return i/2 (rounded down) where i ≥1
    - Left subtree of i: return 2i
    - Right subtree of i: return 2i + 1
    - array[i] is a leaf if and only if 2i > n

```jsx
void heapSort(int *arr, int n) {
    int i;
		// starting from the first parent that occurs from the back of the array
    for(i=n/2-1; i>=0; i--) { // make the maximizing tree
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
```

- `heapify` is a recursive function `lg(n)` which rearranges the highest value among the parent and its children
- first we have to build the maximizing tree, which calls `heapify` n/2 times
    - `for(i=n/2-1; i>=0; i--) {}`
- every time the root node is removed and added to the front of the sorted array, it calls `heapify` once for all the elements in the root → n-1 (excluding the last element after all other elements are moved to sorted array)
- Therefore it is `O(nlgn)` (excluding maxifying heap at the start?)

# Tutorial 3

1. Given an array with content (of type date): 1 Jul, 30 Jan, 22 Mar, 22 Dec, 30 May, 21 Feb, 3 Nov, 7 Jun, 22 Feb, 21 Nov, 30 Dec; all of the same year. Suppose an earlier date is considered bigger than a later date; for example, “30 Jan is bigger than “30 Dec. In order to sort these dates by Heap Sort, let us construct a maximizing heap. Show the content of the array after the heap construction phase.
    1. construct the array into a heap (parent>right child>left child)
    2. call heapify recursively to make the array a heap, exit condition is if node if a leaf node (no children), else compare children with parent node and swap accordingly, (2 comparisons left vs right, then parent node vs larger child + 1 swap if needed)
2. An array of distinct keys in decreasing order is to be sorted (into increasing order) by Heap Sort.
(a) How many comparisons of keys are done in the heap construction phase (Algorithm constructHeap() in lecture notes on Sorting) if there are 10 elements?
    1. 9
    2. How many are done if there are n elements? Show how you derive your answer.
        1. internal node: node with two children
        2. the no. of internal nodes are given by node → n/2 - 1
        3. if n is even, n/2 internal nodes
        4. if n is odd, n-1/2 internal nodes
        5. thus total = 2(n/2-1) + 1
    3. Is an array in decreasing order the best case, the worst case, or an intermediate case for this algorithm? Justify your answer.
        1. best case 
    4. Given k lists with a total of n numbers, where k ≥ 2 and each list has been sorted in decreasing order, design an algorithm to merge the k lists into one list sorted in decreasing order, in running time
    O(n log2 k).
    

# Chapter 6: Greedy Algorithms

## Dijkstra’s Algorithm

- An implementation of Greedy algorithm. Unlike most Greedy algorithm, Dijkstra’s algorithm **can guarantee global optimality**
- Shortest Path Algorithm, can be least number of edges or least total weight
- Applies for weighted directed graph, where weights $w_i>=0$
- Finds the shortest path from the starting node to every other vertex
- Watch proves on Dijkstra’s optimality

# Chapter 7: Kruskal’s Algorithm

- Greedy algorithm
- minimum spanning tree must be acyclic. This is achieved with the Union Find Data Structure
- intuitive understanding
    - start with the lost cost edge
    - check if including the vertex will make the minimum spanning tree acyclic.
    - if it does not, it can be added to the minimun spanning tree
    - continue untill all edges are checked or untill all nodes are visited

## tutorial 7

1.

![photo_3_2023-10-11_17-59-33.jpg](SC2001%20Algorithm%20Design%20&%20Analysis%204d954cb661cb420893d76315df35b941/photo_3_2023-10-11_17-59-33.jpg)

![photo_1_2023-10-11_17-59-33.jpg](SC2001%20Algorithm%20Design%20&%20Analysis%204d954cb661cb420893d76315df35b941/photo_1_2023-10-11_17-59-33.jpg)

![photo_2_2023-10-11_17-59-33.jpg](SC2001%20Algorithm%20Design%20&%20Analysis%204d954cb661cb420893d76315df35b941/photo_2_2023-10-11_17-59-33.jpg)

![photo_4_2023-10-11_17-59-33.jpg](SC2001%20Algorithm%20Design%20&%20Analysis%204d954cb661cb420893d76315df35b941/photo_4_2023-10-11_17-59-33.jpg)

2.

![normal kruskal algo](SC2001%20Algorithm%20Design%20&%20Analysis%204d954cb661cb420893d76315df35b941/photo_5_2023-10-11_17-59-33.jpg)

normal kruskal algo

![red one is time complexity for adjacency matrix](SC2001%20Algorithm%20Design%20&%20Analysis%204d954cb661cb420893d76315df35b941/IMG_6293.jpeg)

red one is time complexity for adjacency matrix

![only connected() will be included in algo. thus, e log v](SC2001%20Algorithm%20Design%20&%20Analysis%204d954cb661cb420893d76315df35b941/IMG_6294.jpeg)

only connected() will be included in algo. thus, e log v

- used for bike path algo to minimise distance from one rest stop to another, allowing ample rest time