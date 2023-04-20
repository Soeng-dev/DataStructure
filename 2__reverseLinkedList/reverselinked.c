#include "reverselinked.h"
#include <stdio.h>
#include <stdlib.h>

RevLList *createRevLList()
{
    return (calloc(1, sizeof(RevLList)));
}

RevLLNode *createRevLLNode(int data)
{
    RevLLNode *new = malloc(sizeof(RevLLNode));

    new->data = data;
    new->pLink = NULL;

    return new;
}

int addRevLLElement(RevLList *pList, RevLLNode element)
{
    RevLLNode *newNode = createRevLLNode(element.data);

    if (!newNode)
        return (FALSE);

    if (!pList->currSize)
        pList->tail.pLink = newNode;
    else
        pList->header.pLink->pLink = newNode;

    pList->header.pLink = newNode;
    ++pList->currSize;

    return (newNode->data);
}

int removeRevLLElement(RevLList *pList)
{
    if (pList->currSize <= 0)
        return (FALSE);

    if (pList->currSize == 1)
    {
        free(pList->tail.pLink);
        pList->tail.pLink = NULL;
        pList->header.pLink = NULL;
    }
    else
    {
        RevLLNode *newFirst;
        for (newFirst = pList->tail.pLink;
             newFirst->pLink->pLink;
             newFirst = newFirst->pLink)
            ;
        free(pList->header.pLink);
        newFirst->pLink = NULL;
        pList->header.pLink = newFirst;
    }
    --pList->currSize;

    return TRUE;
}

void clearRevLList(RevLList *pList)
{
    while (pList->currSize > 0)
        removeRevLLElement(pList);
}

int getRevLListLength(RevLList *pList)
{
    return pList->currSize;
}

void deleteRevLList(RevLList *pList)
{
    clearRevLList(pList);
    free(pList);
}
