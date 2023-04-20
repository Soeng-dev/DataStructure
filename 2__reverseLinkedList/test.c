#include <stdio.h>
#include <stdlib.h>
#include "./reverselinked.h"

int main(int argc, char *argv[])
{
	int i = 0;
	int listCount = 0;
	RevLList *pList = NULL;
	RevLLNode *pValue = NULL;

	pList = createRevLList();
	if (pList != NULL)
	{
		RevLLNode node;

		node.data = 1;
		addRevLLElement(pList, node);

		node.data = 3;
		addRevLLElement(pList, node);

		node.data = 5;
		addRevLLElement(pList, node);

		listCount = getRevLListLength(pList);
		printf("list length : %d\n", listCount);
		for (RevLLNode *pValue = pList->tail.pLink; pValue; pValue = pValue->pLink)
			printf("%d\n", pValue->data);

		removeRevLLElement(pList);
		listCount = getRevLListLength(pList);
		printf("list length : %d\n", listCount);
		for (RevLLNode *pValue = pList->tail.pLink; pValue; pValue = pValue->pLink)
			printf("%d\n", pValue->data);
		

		deleteRevLList(pList);
	}

	return 0;
}