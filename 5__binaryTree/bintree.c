#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree* binTree = calloc(1, sizeof(BinTree));
	if (!binTree)
		return NULL;

	binTree->pRootNode = calloc(1, sizeof(BinTreeNode));
	if (!binTree->pRootNode)
		return NULL;
	binTree->pRootNode->data = rootNode.data;

	return binTree;
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode* newLeft = calloc(1, sizeof(BinTreeNode));
	if (!newLeft)
		return NULL;
	newLeft->data = element.data;

	newLeft->pLeftChild = pParentNode->pLeftChild;
	pParentNode->pLeftChild = newLeft;

	return newLeft;
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode* newRight = calloc(1, sizeof(BinTreeNode));
	if (!newRight)
		return NULL;
	newRight->data = element.data;

	newRight->pRightChild = pParentNode->pRightChild;
	pParentNode->pRightChild = newRight;

	return newRight;
}

void deleteBinTree(BinTree* pBinTree)
{
	if (!pBinTree)
		return;

	clearBinTreeNodes(pBinTree->pRootNode);
	free(pBinTree);
}

void clearBinTreeNodes(BinTreeNode* rootNode)
{
	if (!rootNode)
		return;

	BinTreeNode* right = rootNode->pRightChild;
	BinTreeNode* left = rootNode->pLeftChild;
	free(rootNode);

	clearBinTreeNodes(left);
	clearBinTreeNodes(right);

}
