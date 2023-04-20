#ifndef REVERSELINKED_H
#define REVERSELINKED_H

#define TRUE 1
#define FALSE 0

typedef struct ReverseLinkedListNode
{
	int data;
	struct ReverseLinkedListNode *pLink;
} RevLLNode;

typedef struct ReverseLinkedList
{
	int currSize;
	RevLLNode header;
	RevLLNode tail;
} RevLList;

RevLList* createRevLList();
int addRevLLElement(RevLList* pList, RevLLNode element);
int removeRevLLElement(RevLList* pList);

void clearRevLList(RevLList* pList);
int getRevLListLength(RevLList* pList);
void deleteRevLList(RevLList* pList);

#endif
