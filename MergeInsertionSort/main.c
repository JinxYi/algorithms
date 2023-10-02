#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Include this for random number generation

typedef struct _listnode
{
    int item;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist {
   int size;
   ListNode *head;
} LinkedList;

int insertNode(LinkedList *ll, int index, int coin);
int removeNode(LinkedList *ll, int index);
ListNode *findNode(LinkedList ll, int index);
void removeAllItems(LinkedList *ll);
void printList(LinkedList *ll);

void mergeSort(LinkedList *ll);
void merge(LinkedList *ll, LinkedList *left, LinkedList *right);
void insertionSort(LinkedList *ll);
void swap(ListNode *node1, ListNode *node2);
int findIndex(LinkedList *ll, ListNode *node);
void mergeInsertionSort(LinkedList *ll, int S);

int main()
{
    int listSize = 60;
    int x = 100;
    
    srand(time(NULL)); //random num generator

    LinkedList ll;
    ll.size = 0;
    ll.head = NULL;

    for (int i = 0; i < listSize; i++) {
        insertNode(&ll, i, rand() % (x+1));
    }
    printList(&ll);
    mergeInsertionSort(&ll, 5);
//    mergeSort(&ll);
//    insertionSort(&ll);

    printList(&ll);
    removeAllItems(&ll);
}

void mergeInsertionSort(LinkedList *ll, int S)
{
    if (ll->size <= 1) {
        return; // Nothing to sort
    }
    printf("list size %d\n", ll->size);
    if (ll->size > S)
    {
        printf("merge sort\n");
        int mid = ll->size / 2;

        LinkedList left, right;
        left.size = mid;
        right.size = ll->size - mid;
        left.head = ll->head;
        ListNode *current = ll->head;

        // Split the linked list into two halves
        for (int i = 0; i < mid - 1; i++) {
            current = current->next;
        }

        right.head = current->next;
        current->next = NULL;

        // Recursively sort both halves
        mergeInsertionSort(&left, S);
        mergeInsertionSort(&right, S);

        // Merge the sorted halves
        merge(ll, &left, &right);
    }
    else {
        printf("insert sort\n");
		insertionSort(ll);
	}
}

void insertionSort(LinkedList *ll)
{
    if (ll->size <= 1) {
        return; // Nothing to sort
    }

    ListNode *sorted = NULL; // Initially, the sorted list is empty

    ListNode *current = ll->head;

    while (current != NULL) {
        ListNode *next = current->next;
        // Insert current node into the sorted list
        if (sorted == NULL || current->item <= sorted->item) {
            current->next = sorted;
            sorted = current;
        } else {
            ListNode *insertionPoint = sorted;
            while (insertionPoint->next != NULL && insertionPoint->next->item < current->item) {
                insertionPoint = insertionPoint->next;
            }
            current->next = insertionPoint->next;
            insertionPoint->next = current;
        }
        current = next;
    }

    // Update the head of the linked list to point to the sorted list
    ll->head = sorted;
}

void swap(ListNode *node1, ListNode *node2)
{
    int temp = node1->item;
    node1->item = node2->item;
    node2->item = temp;
}

int findIndex(LinkedList *ll, ListNode *node)
{
    int index = 0;
    ListNode *current = ll->head;
    while (current != NULL) {
        if (current == node) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1; // Node not found
}

void mergeSort(LinkedList *ll)
{
    if (ll->size <= 1) {
        return; // Nothing to sort
    }

    int mid = ll->size / 2;

    LinkedList left, right;
    left.size = mid;
    right.size = ll->size - mid;
    left.head = ll->head;
    ListNode *current = ll->head;

    // Split the linked list into two halves
    for (int i = 0; i < mid - 1; i++) {
        current = current->next;
    }

    right.head = current->next;
    current->next = NULL;

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


// LinkedList methods
int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size)
		return 0;

        if (index == 0){
		cur = ll->head;
		ll->head = (ListNode*) malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 1;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(*ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 1;
	}

	return 0;
}


int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index > ll->size)
		return 0;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;
		return 1;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(*ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return 0;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 1;
	}

	return 0;
}

ListNode *findNode(LinkedList ll, int index){

	ListNode *temp;

	if (index < 0 || index >= ll.size)
		return NULL;

	temp = ll.head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

void removeAllItems(LinkedList *ll)
{
	ListNode *cur = ll->head;
	ListNode *tmp;

	while (cur != NULL){
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	ll->head = NULL;
	ll->size = 0;
}

void printList(LinkedList *ll)
{
    ListNode *cur = ll->head;
    while (cur != NULL) {
        printf("%d -> ", cur->item);
        cur = cur->next;
    }
    printf("NULL\n");
}


