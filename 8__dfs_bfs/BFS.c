#include "BFS.h"

#include <stdio.h>

void bfsTraverse(LinkedGraph *g)
{
    CircularQueue *nodes = createCircularQueue(g->maxVertexCount - 1);

    put(nodes, g->ppAdjEdge[0]->headerNode.pLink->data);
    while (! nodes->isEmpty)
    {
        int currentNode = get(nodes);
        pListNode node = g->ppAdjEdge[currentNode]->headerNode.pLink;
        printf("%d  ", node->data);
        
        for (node = node->pLink;node;node = node->pLink)
        {
            if (g->visited[node->data])
                continue;
            else
                {put(nodes, node->data); printf("putted %d ", node->data);}
        }
        int a;
        scanf("%d",&a);
    }
    
    return ;
}