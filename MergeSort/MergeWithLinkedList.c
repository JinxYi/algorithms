#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 9

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
ListNode *findNode(LinkedList ll, int index);
void removeAllItems(LinkedList *ll);

void mergeSort(LinkedList *ll);
void split(LinkedList *ll, LinkedList *left, LinkedList *right);
void merge(LinkedList *ll, LinkedList *left, LinkedList *right);
void printList(LinkedList *ll);

int main()
{
    int listSize, x;
    printf("Enter an array size: ");
    scanf("%d", &listSize);
    printf("Enter max value of record: ");
    scanf("%d", &x);

    LinkedList ll;
    ll.size = 0;
    ll.head = NULL;
    for (int i = 0; i < listSize; i++) {
        insertNode(&ll, i, rand() % (x+1));
    }
    printList(&ll);
    mergeSort(&ll);

    printList(&ll);
    removeAllItems(&ll);
    return 0;
}


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

void split(LinkedList *ll, LinkedList *left, LinkedList *right) {
    int mid = ll->size / 2;

    left->size = mid;
    right->size = ll->size - mid;
    left->head = ll->head;
    ListNode *current = ll->head;

    // Split the linked list into two halves
    for (int i = 0; i < mid - 1; i++) {
        current = current->next;
    }

    right->head = current->next;
    current->next = NULL;
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

    // copy remaining elements
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
	if (ll == NULL || index < 0 || index > ll->size) return 0;

	ListNode *pre, *cur;

    if (index == 0) {
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
