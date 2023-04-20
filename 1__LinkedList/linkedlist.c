#include <stdlib.h>
#include <stdio.h>
#include "./linkedlist.h"

LinkedList* createLinkedList()
{
    return ((LinkedList*)calloc(1, sizeof(LinkedList)));
}

ListNode* createListNode(int data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));

    if (!node)
        return (NULL);
    node->data = data;
    node->pLink = NULL;
    return (node);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
    ListNode* oneFrontNode = getLLElement(pList, position - 1);
    ListNode* newNode = createListNode(element.data);

    if (!newNode || position > pList->currentElementCount)
        return (FALSE);

    if (!pList->currentElementCount)
        pList->headerNode.pLink = newNode;
    else
    {
        newNode->pLink = oneFrontNode->pLink;
        oneFrontNode->pLink = newNode;
        printf("new : %d\n", oneFrontNode->pLink->data);
    }
    ++pList->currentElementCount;
    return (newNode->data);
}


int removeLLElement(LinkedList* pList, int position)
{
    if (position > pList->currentElementCount - 1)
        return FALSE;
    ListNode* oneFrontNode = getLLElement(pList, position - 1);
    ListNode* pTargetNode = oneFrontNode->pLink;

    if (oneFrontNode->pLink)
        oneFrontNode->pLink = oneFrontNode->pLink->pLink;
    int removedData = pTargetNode->data;
    free(pTargetNode);
    --pList->currentElementCount;
    return (removedData);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
    ListNode* pTarget = &pList->headerNode;

    if (position > pList->currentElementCount)
        return (NULL);

    for (int i = 0; i <= position; ++i)
        pTarget = pTarget->pLink;

    return (pTarget);
}

void clearLinkedList(LinkedList* pList)
{
    for (; pList->currentElementCount > 0; --pList->currentElementCount)
        removeLLElement(pList, 0);
}

int getLinkedListLength(LinkedList* pList)
{
    return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
    clearLinkedList(pList);
    free(pList);
}