#include <stdio.h>
#include <stdlib.h>
#include "./linkedlist.h"

int main(int argc, char* argv[]) {
	int i = 0;
	int listCount = 0;
	LinkedList* pList = NULL;
	ListNode* pValue = NULL;

	pList = createLinkedList(6);
	if (pList != NULL)
	{
		ListNode node;

		// 리스트 초기화: 1, 3, 5 추가.
		node.data = 1;
		addLLElement(pList, 0, node);

		node.data = 3;
		addLLElement(pList, 1, node);

		node.data = 5;
		addLLElement(pList, 2, node);



		listCount = getLinkedListLength(pList);
		printf("list length : %d\n", listCount);
		for (i = 0; i < listCount; i++) {
			pValue = getLLElement(pList, i);
			if (pValue)
				printf("위치[%d]-%d\n", i, pValue->data);
		}

		// 첫번째 원소 제거.

		removeLLElement(pList, 0);
		listCount = getLinkedListLength(pList);
		printf("list length : %d\n", listCount);
		for (i = 0; i < listCount; i++) {
			pValue = getLLElement(pList, i);
			if (pValue)
				printf("위치[%d]-%d\n", i, pValue->data);
		}

		deleteLinkedList(pList);
	}

	return 0;
}