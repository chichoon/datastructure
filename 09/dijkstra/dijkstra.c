#include "dijkstra.h"

int	*createRouteArray(ArrayGraph *graph, int start)
{
	int	*arr;

	arr = malloc(sizeof(int) * graph->maxVertexCount);
	if (!arr)
		return (NULL);
	for (int i = 0; i < graph->maxVertexCount; i++)
	{
		if (i == start)
			arr[i] = 0;
		else
			arr[i] = graph->ppAdjEdge[start][i];
	}
	return (arr);
}

int	*createVisitedArray(ArrayGraph *graph, int start)
{
	int *arr;

	arr = malloc(sizeof(int) * graph->maxVertexCount);
	if (!arr)
		return (NULL);
	for (int i = 0; i < graph->maxVertexCount; i++)
		arr[i] = NOT_VISITED;
	arr[start] = VISITED;
	return (arr);
}

void	initEdgeToInf(ArrayGraph *graph)
{
	for (int i = 0; i < graph->maxVertexCount; i++)
	{
		for (int j = 0; j < graph->maxVertexCount; j++)
		{
			if (i == j)
				graph->ppAdjEdge[i][j] = 0;
			else
				graph->ppAdjEdge[i][j] = INF;
		}
	}
}

int	*dijkstra(ArrayGraph *graph, int start)
{
	int	*arrDist;
	int	*arrVisited;
	int	minRoute;
	int	temp;

	arrDist = createRouteArray(graph, start);
	arrVisited = createVisitedArray(graph, start);
	if (!arrDist || !arrVisited)
		return (NULL);
	for (int i = 0; i < graph->maxVertexCount; i++)
	{
		//가장 가까운 정점찾기 ↓
		minRoute = INF;
		for (int j = 0; j < graph->maxVertexCount; j++)
		{
			if ( !arrVisited[j] && minRoute > arrDist[j] )
			{
				minRoute = arrDist[j];
				temp = j;
			}
		}
		arrVisited[temp] = VISITED;
		printf("temp: %d\n", temp);
		for (int j = 0; j < graph->maxVertexCount; j++)
		{
			if (arrDist[j] > arrDist[temp] + graph->ppAdjEdge[temp][j] && !arrVisited[j])
			{
				printf("arrDist[%d]: %d, arrDist[%d] + Edge[%d][%d] = %d\n", j, arrDist[j], temp, temp, j, arrDist[temp] + graph->ppAdjEdge[temp][j]);
				arrDist[j] = arrDist[temp] + graph->ppAdjEdge[temp][j];
			}
		}
	}
	free(arrVisited);
	return (arrDist);
}

int	main(void)
{
	ArrayGraph	*graph;
	int			*arrDist;
	int			startPoint;

	graph = createArrayGraph(6);
	for (int i = 0; i < 6; i++)
		addVertexAG(graph, i);
	initEdgeToInf(graph);
	addEdgewithWeightAG(graph, 0, 1, 1);
	addEdgewithWeightAG(graph, 0, 2, 4);
	addEdgewithWeightAG(graph, 1, 2, 2);
	addEdgewithWeightAG(graph, 2, 3, 1);
	addEdgewithWeightAG(graph, 3, 4, 8);
	addEdgewithWeightAG(graph, 4, 5, 4);
	addEdgewithWeightAG(graph, 3, 5, 3);
	startPoint = 0;
	arrDist = dijkstra(graph, startPoint);
	for (int i = 0; i < 6; i++)
		printf("%d to %d shortest distance :%d\n", startPoint, i, arrDist[i]);
	free(arrDist);
	deleteArrayGraph(graph);
}
