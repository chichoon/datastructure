#include "prim.h"

int	ifTraversedAll(ArrayGraph *graph, int *vertexArray)
{
	for (int i = 0; i < graph->maxVertexCount; i++)
		if (graph->pVertex[i] != vertexArray[i])
			return (FALSE);
	return (TRUE);
}

ArrayGraph	*prim(ArrayGraph *originalGraph)
{
	ArrayGraph		*returnGraph;
	int				*vertexArray;
	int				minWeight;
	int				vertexTemp;

	//Array, Graph, Queue 생성
	returnGraph = createArrayGraph(originalGraph->maxVertexCount);
	vertexArray = malloc(sizeof(int) * originalGraph->maxVertexCount);
	if (!returnGraph || !vertexArray)
		return (NULL);
	//Array, Graph, Queue 초기화
	memset(vertexArray, FALSE, sizeof(int) * originalGraph->maxVertexCount);
	for (int i = 0; i < originalGraph->maxVertexCount; i++)
		if (originalGraph->pVertex[i] == USED)
			addVertexAG(returnGraph, i);
	//시작점 방문 체크
	vertexArray[0] = VISITED;
	for (int i = 0; i < originalGraph->maxVertexCount; i++)
	{
		minWeight = INF;
		for (int j = 0; j < originalGraph->maxVertexCount; j++)
		{
			if (!vertexArray[j]
				&& originalGraph->ppAdjEdge[i][j] > 0
				&& minWeight > originalGraph->ppAdjEdge[i][j] )
			{
				minWeight = originalGraph->ppAdjEdge[i][j];
				vertexTemp = j;
			}
		}
		addEdgewithWeightAG(returnGraph, i, vertexTemp, minWeight);
	}
	return (returnGraph);
}

int main(void)
{
	ArrayGraph *graph;
	ArrayGraph *mst;

	graph = createArrayGraph(6);
	if (!graph)
		return (0);
	for (int i = 0; i < 6; i++)
		addVertexAG(graph, i);
	addEdgewithWeightAG(graph, 0, 1, 4);
	addEdgewithWeightAG(graph, 0, 2, 3);
	addEdgewithWeightAG(graph, 1, 2, 2);
	addEdgewithWeightAG(graph, 2, 3, 1);
	addEdgewithWeightAG(graph, 3, 4, 1);
	addEdgewithWeightAG(graph, 3, 5, 5);
	addEdgewithWeightAG(graph, 4, 5, 6);
	mst = prim(graph);
	if (!mst)
		return (0);
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			if (i < j && mst->ppAdjEdge[i][j] > 0)
				printf("%d to %d : %d\n", i, j, mst->ppAdjEdge[i][j]);
	deleteArrayGraph(graph);
	deleteArrayGraph(mst);
}
