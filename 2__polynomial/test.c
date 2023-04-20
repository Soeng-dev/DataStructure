#include "polinomial.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// DoublyList *list = createDoublyList();

	// DoublyListNode *node1 = calloc(1, sizeof(DoublyListNode));
	// // node1->data = 3;

	// DoublyListNode *node2 = calloc(1, sizeof(DoublyListNode));
	// // node2->data = 32;

	// DoublyListNode *node3 = calloc(1, sizeof(DoublyListNode));
	// // node3->data = 34;

	// DoublyListNode *node4 = calloc(1, sizeof(DoublyListNode));
	// // node4->data = 345;

	// addDLElement(list, 1, node1);
	// addDLElement(list, 3, node2);
	// addDLElement(list, 1, node2);
	// addDLElement(list, 2, node3);
	// addDLElement(list, 2, node4);
	// displayDoublyList(list);
	// clearDoublyList(list);
	// deleteDoublyList(list);

	int ar1[4] = {1, 0, 4, 5};
	int ar2[7] = {5, 0, 2, 4, 5, 0, 1};

	DoublyList *p1 = createPolinomial(ar1, 3);
	DoublyList *p2  = createPolinomial(ar2, 6);

	// displayDoublyList(p1);
	// displayDoublyList(p2);


	addPolinomial(p1, p2);
	// displayDoublyList(p1);
	// displayDoublyList(p2);

}