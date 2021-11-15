#include "prim.h"

int	ifTraversedAll(ArrayGraph *graph, int *vertexArray)
{
	for (int i = 0; i < graph->maxVertexCount; i++)
		if (graph->pVertex[i] != vertexArray[i])
			return (FALSE);
	return (TRUE);
}

int	findStartPoint(ArrayGraph *graph)
{
	int	startPoint = -1;

	for (int i = 0; i < graph->maxVertexCount; i++)
	{
		if (graph->pVertex[i] == USED)
		{
			startPoint = i;
			break ;
		}
	}
	return (startPoint);
}

int	findIfCircular(ArrayGraph *graph, int startNode)
{
	ArrayStack	*stack;
	StackNode	element;
	int			now;
	int			*vertexArray;

	stack = createArrayStack(graph->maxVertexCount);
	vertexArray = malloc(sizeof(int) * graph->maxVertexCount);
	if (!stack || !vertexArray)
		return (-1);
	memset(vertexArray, FALSE, sizeof(int) * graph->maxVertexCount);
	vertexArray[startNode] = TRUE;
	element.data = startNode;
	pushAS(stack, element);
	while (!isArrayStackEmpty(stack))
	{
		now = stackpop(arr);

	}
}

ArrayGraph	*prim(ArrayGraph *originalGraph)
{
	ArrayGraph	*returnGraph;
	int			*vertexArray;
	int			v = -1;
	int			minWeight;

	//Array, Graph 초기화
	returnGraph = createArrayGraph(originalGraph->maxVertexCount);
	vertexArray = malloc(sizeof(int) * originalGraph->maxVertexCount);
	if (!returnGraph || !vertexArray)
		return (NULL);
	memset(vertexArray, FALSE, sizeof(int) * originalGraph->maxVertexCount);
	//Graph의 Vertex중 첫번째로 등장하는 Vertex를 시작점으로 삼음
	v = findStartPoint(originalGraph);
	if (v < 0)
		return (NULL);
	vertexArray[v] = TRUE;
	//Prim 알고리즘 시작
	for (int j = 0; j < originalGraph->maxVertexCount; j++)
	{
		minWeight = INT32_MAX;
		for (int i = 0; i < originalGraph->maxVertexCount; i++)
		{
			if (
				originalGraph->ppAdjEdge[v][i] > 0
				&& originalGraph->ppAdjEdge[v][i] < minWeight
				&& vertexArray[i] == NOT_USED
				)
			{

			}
		}
	}
}
