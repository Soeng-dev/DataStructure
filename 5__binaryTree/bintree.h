﻿#ifndef _BIN_TREE_
#define _BIN_TREE_

#include <stdlib.h>

typedef int BinTreeNodeData;

typedef struct BinTreeNodeType
{
	BinTreeNodeData data;

	struct BinTreeNodeType* pLeftChild;
	struct BinTreeNodeType* pRightChild;
} BinTreeNode;

typedef struct BinTreeType
{
	BinTreeNode* pRootNode;
} BinTree;

BinTree* makeBinTree(BinTreeNode rootNode);
void deleteBinTree(BinTree* pBinTree);
void clearBinTreeNodes(BinTreeNode* rootNode);

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);




#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif
