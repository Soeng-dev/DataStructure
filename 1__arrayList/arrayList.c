#include “./arraylist.h”
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ArrayList* createArrayList(int maxElementCount)
{
	ArrayList *tmp = (ArrayList *)calloc(1, sizeof(ArrayList));
	tmp->maxElementCount = maxElementCount;
	return tmp;
}
void deleteArrayList(ArrayList *pList)
{
	free(pList->pElement);
	free(pList);
	pList = NULL;
}
int isArrayListFull(ArrayList* pList)
{
	return pList->maxElementCount == pList->currentElementCount ? TRUE : FALSE;
}
int addALElement(ArrayList *pList, int position, ArrayListNode element)
{
	ArrayListNode *tmp;
	if (isArrayListFull(pList))
		pList->maxElementCount *= 2;
	if ((pList->currentElementCount && position > pList->currentElementCount))
		return FALSE;
	
	return TRUE;
}
int removeALElement(ArrayList* pList, int position)
{
	ArrayListNode *tmp;
	if (position >= pList->currentElementCount || pList->currentElementCount == 0)
		return FALSE;
	memmove(pList->pElement + position, pList->pElement + position + 1, sizeof(ArrayListNode) * (pList->currentElementCount - position));
	pList->currentElementCount--;
	tmp = (ArrayListNode *)calloc(pList->currentElementCount, sizeof(ArrayListNode));
	memcpy(tmp, pList->pElement, sizeof(ArrayListNode) * pList->currentElementCount);
	free(pList->pElement);
	pList->pElement = tmp;
	return TRUE;
}
ArrayListNode* getALElement(ArrayList* pList, int position)
{
	return position < pList->maxElementCount ? pList->pElement + position : NULL;
}
void displayArrayList(ArrayList* pList)
{
	for (int i = 0 ; i < pList->currentElementCount ; i++)
		printf(“%d “,(pList->pElement + i)->data);
}
void clearArrayList(ArrayList* pList)
{
	free(pList->pElement);
	pList->pElement = NULL;
	pList->currentElementCount = 0;
}
int getArrayListLength(ArrayList *pList)
{
	return pList->currentElementCount;
}