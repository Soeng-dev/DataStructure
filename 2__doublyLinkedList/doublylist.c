#include "./doublylist.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

DoublyList *createDoublyList()
{
	return (calloc(1, sizeof(DoublyList)));
}

void removeAllDLElement(DoublyList *pList)
{
	DoublyListNode *next;

	// code considered for position < 0 
	// for (DoublyListNode *left = pList->headerNode.pLLink;
	// 	 left; left = next)
	// {
	// 	next = left->pLLink;
	// 	free(left);
	// }
	for (DoublyListNode *right = pList->headerNode.pRLink;
		 right; right = next)
	{
		next = right->pRLink;
		free(right);
	}
	pList->currentElementCount = 0;
	pList->headerNode.pLLink = NULL;
	pList->headerNode.pRLink = NULL;
	return;
}

void deleteDoublyList(DoublyList *pList)
{
	clearDoublyList(pList);
	free(pList);
}

DoublyListNode *getDLElement(DoublyList *pList, int position)
{
	DoublyListNode *target;

	if (position < 0)
		return (NULL);

	target = &pList->headerNode;
	for (int i = 1; i < position; ++i)
		target = target->pRLink;

	//code considered for position < 0
	// if (position > 0)
	// {
	// 	target = pList->headerNode.pRLink;
	// 	for (int i = 1; i < position; ++i)
	// 		target = target->pRLink;
	// }
	// else if (position < 0)
	// {
	// 	target = pList->headerNode.pLLink;
	// 	for (int i = 1; i < position; ++i)
	// 		target = target->pLLink;
	// }
	// else
	// return NULL;
	return target;
}

int addDLElement(DoublyList *pList, int position, DoublyListNode *element)
{
	if (position <= 0 || position > pList->currentElementCount + 1)
		return (FALSE);

	DoublyListNode *oneFrontNode = getDLElement(pList, position - 1);

	element->pLLink = oneFrontNode;
	element->pRLink = oneFrontNode->pRLink;
	if (element->pRLink)
		element->pRLink->pLLink = element;
	oneFrontNode->pRLink = element;
	// element->pRLink = old->pRLink;
	// element->pLLink = old;
	// element->pRLink->pLLink = element;
	// element->pLLink->pRLink = element;

	++pList->currentElementCount;

	return (TRUE);
}

int removeDLElement(DoublyList *pList, int position)
{
	DoublyListNode *target = getDLElement(pList, position);

	target->pRLink->pLLink = target->pLLink;
	target->pLLink->pRLink = target->pRLink;

	--pList->currentElementCount;

	memset(target, 0, sizeof(DoublyListNode));
	free(target);
}

void clearDoublyList(DoublyList *pList)
{
	removeAllDLElement(pList);
	return;
}

int getDoublyListLength(DoublyList *pList)
{
	return (pList->currentElementCount);
}

void displayDoublyList(DoublyList *pList)
{
	DoublyListNode *next = NULL;

	printf("curr : %d\n", pList->currentElementCount);
	for (DoublyListNode *right = pList->headerNode.pRLink;
		 right; right = next)
	{
		printf("%d\n", right->data);
		next = right->pRLink;
	}
	return;
}