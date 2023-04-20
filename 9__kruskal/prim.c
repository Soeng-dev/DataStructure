#include "prim.h"

int getFirstVertex(ArrayGraph* g)
{
	int first;
	for (first = 0; !g->pVertex[first]; ++first);
	return first;
}

HeapData getFirstEdge(ArrayGraph* g)
{
	HeapData firstEdge;
	for (firstEdge.fromVertex = getFirstVertex(g),
		firstEdge.toVertex = firstEdge.fromVertex + 1,
		firstEdge.weight = g->ppAdjEdge[firstEdge.fromVertex][firstEdge.toVertex]

		;!g->ppAdjEdge[firstEdge.fromVertex][firstEdge.toVertex]

		;++firstEdge.toVertex,
		firstEdge.weight = g->ppAdjEdge[firstEdge.fromVertex][firstEdge.toVertex]);

	return firstEdge;
}



ArrayGraph* getMstByPrim(ArrayGraph* g)
{
	if (!g || !g->ppAdjEdge || !g->pVertex || !g->currentVertexCount) return NULL;

	Heap* edgeHeap = createHeap(g->currentVertexCount * (g->currentVertexCount - 1));
	if (!edgeHeap) return NULL;

	ArrayGraph* mst = createArrayGraph(g->maxVertexCount);
	if (!mst) return NULL;

	//Select min edge which doesn't make cycle
	int* parents = malloc(g->maxVertexCount * sizeof(int));
	if (!parents) return NULL;
	for (int i = 0; i < g->maxVertexCount;++i) parents[i] = i;


	int firstVertex = getFirstVertex(g);
	pushHeapData(edgeHeap, getFirstEdge(g));

	while (edgeHeap->currentCount)
	{
		//pop min adj edge, connect to mst
		HeapData minEdge = popMinData(edgeHeap);
		clearHeapdata(edgeHeap);
		addEdgewithWeightAG(mst, minEdge.fromVertex, minEdge.toVertex, minEdge.weight);
		unionParent(parents, minEdge.fromVertex, minEdge.toVertex);

		//push adjacent edges of new vertex after check if minEdge.toVertex is vertex of mst(same as union find)
		//adj.toVertex is new vertex
		HeapData adj;
		for (adj.fromVertex = minEdge.toVertex,
			adj.toVertex = 0,
			adj.weight = g->ppAdjEdge[adj.fromVertex][adj.toVertex]

			;adj.toVertex < mst->maxVertexCount

			;++adj.toVertex,
			adj.weight = g->ppAdjEdge[adj.fromVertex][adj.toVertex])
		{
			if (haveSameParent(parents, firstVertex, adj.toVertex))
				continue;

			if (g->ppAdjEdge[adj.fromVertex][adj.toVertex] != 0)
				pushHeapData(edgeHeap, adj);
		}
	}

	free(parents);
	deleteHeap(edgeHeap);

	return mst;
}