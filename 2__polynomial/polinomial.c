#include "./polinomial.h"

// Assuming that coefArr starts from coef of max degree
DoublyList *createPolinomial(int *coefArr, int maxDegree)
{
    DoublyList *list = malloc(sizeof(DoublyList));
    DoublyListNode node;

    for (int i = maxDegree; i >= 0; --i)
    {
        node.coef = coefArr[i];
        node.degree = maxDegree - i;
        addDLElement(list, 0, &node);
    }

    return list;
}

DoublyListNode *createPoliNode(int coef, int degree)
{
    DoublyListNode *new = malloc(sizeof(DoublyListNode));

    new->coef = coef;
    new->degree = degree;

    return new;
}

void addNodeFront(DoublyList *targetList, DoublyListNode *target, DoublyListNode *toAdd)
{
    DoublyListNode *new = createPoliNode(toAdd->coef, toAdd->degree);

    new->pLLink = target->pLLink;
    new->pRLink = target;
    if (target->pLLink)
        target->pLLink->pRLink = new;
    target->pLLink = new;
    ++targetList->currentElementCount;
    
    return;
}

void addNodeBehind(DoublyList *targetList, DoublyListNode *target, DoublyListNode *toAdd)
{
    DoublyListNode *new = createPoliNode(toAdd->coef, toAdd->degree);

    new->pLLink = target;
    new->pRLink = target->pRLink;
    if (target->pRLink)
        target->pRLink->pLLink = new;
    target->pRLink = new;
    ++targetList->currentElementCount;
    
    return;
}

// Assunming that poliList starts from max degree
void addPolinomial(DoublyList *targetList, DoublyList *toAddList)
{
    DoublyListNode *target = targetList->headerNode.pRLink,
                   *toAdd = toAddList->headerNode.pRLink;
    while (toAdd)
    {
        if (target->degree > toAdd->degree)
            target = target->pRLink;
        else if (target->degree < toAdd->degree)
        {
            addNodeFront(targetList, target, toAdd);
            target = target->pRLink;
        }
        else if (target->degree == toAdd->degree)
        {
            target->coef += toAdd->coef;
            target = target->pRLink;
            toAdd = toAdd->pRLink;
        }
    }
    
    return ;
}