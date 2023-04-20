#include <stdio.h>
#include "bintree.h"

int main()
{
	BinTreeNode data;
	data.data = 'a';

	BinTree* tree = makeBinTree(data);

	data.data = 'l';
	insertLeftChildNodeBT(tree->pRootNode, data);
	data.data = 'r';
	insertRightChildNodeBT(tree->pRootNode, data);

	insertRightChildNodeBT(tree->pRootNode->pLeftChild, data);
	printf("%c\n%c\t%c\n", tree->pRootNode->data, tree->pRootNode->pLeftChild->data, tree->pRootNode->pRightChild->data);
	printf("%c\n", tree->pRootNode->pLeftChild->pRightChild->data);

	deleteBinTree(tree);
}