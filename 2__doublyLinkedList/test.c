#include "./doublylist.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    DoublyList *list = createDoublyList();

    DoublyListNode *node1 = calloc(1, sizeof(DoublyListNode));
    node1->data = 3;

    DoublyListNode *node2 = calloc(1, sizeof(DoublyListNode));
    node2->data = 32;

    DoublyListNode *node3 = calloc(1, sizeof(DoublyListNode));
    node3->data = 34;

    DoublyListNode *node4 = calloc(1, sizeof(DoublyListNode));
    node4->data = 345;

    addDLElement(list, 1, node1);
    addDLElement(list, 3, node2);
    addDLElement(list, 1, node2);
    addDLElement(list, 2, node3);
    addDLElement(list, 2, node4);
    displayDoublyList(list);
    clearDoublyList(list);
    deleteDoublyList(list);
}