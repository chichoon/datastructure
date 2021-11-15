#include "arraygraph.h"

ArrayGraph* createArrayGraph(int maxVertexCount)
{
	ArrayGraph *graph;

	graph = calloc(1, sizeof(ArrayGraph));
	if (!graph)
		return (NULL);
	graph->maxVertexCount = maxVertexCount;
	graph->currentVertexCount = 0;
	graph->graphType = GRAPH_UNDIRECTED;
	graph->ppAdjEdge = (int **)calloc(maxVertexCount, sizeof(int *));
	if (!graph->ppAdjEdge)
	{
		free(graph);
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++)
	{
		graph->ppAdjEdge[i] = (int *)calloc(maxVertexCount, sizeof(int));
		if (!graph->ppAdjEdge[i])
		{
			for (int j = 0; j < i; j++)
				free(graph->ppAdjEdge[j]);
			free(graph);
			return (NULL);
		}
	}
	graph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	if (!graph->pVertex)
	{
		for (int i = 0; i < maxVertexCount; i++)
			free(graph->ppAdjEdge[i]);
		free(graph);
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++)
		graph->pVertex[i] = NOT_USED;
	return (graph);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph *dirGraph;

	dirGraph = (ArrayGraph *)calloc(1, sizeof(ArrayGraph));
	if (!dirGraph)
		return (NULL);
	dirGraph->maxVertexCount = maxVertexCount;
	dirGraph->graphType = GRAPH_DIRECTED;
	dirGraph->currentVertexCount = 0;
	dirGraph->ppAdjEdge = calloc(maxVertexCount, sizeof(int *));
	if (!dirGraph->ppAdjEdge)
	{
		free(dirGraph);
		return (NULL);
	}
	for (int i = 0; i< maxVertexCount; i++)
		dirGraph->ppAdjEdge[i] = calloc(maxVertexCount, sizeof(int));
	dirGraph->pVertex = calloc(maxVertexCount, sizeof(int));
	if (!dirGraph->pVertex)
	{
		for (int i = 0; i < maxVertexCount; i++)
			free(dirGraph->ppAdjEdge[i]);
		free(dirGraph);
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++) {
		dirGraph->pVertex[i] = NOT_USED;
	}
	return (dirGraph);
}

void deleteArrayGraph(ArrayGraph* pGraph)
{
	free(pGraph->pVertex);
	for (int i = 0; i < pGraph->maxVertexCount; i++) {
		free(pGraph->ppAdjEdge[i]);
	}
	free(pGraph->ppAdjEdge);
	free(pGraph);
}

int isEmptyAG(ArrayGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		if (pGraph->pVertex[i] == USED)
			return (FALSE);
	return (TRUE);
}

int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (vertexID >= pGraph->maxVertexCount || vertexID < 0)
		return (FAIL);
	if (checkVertexValid(pGraph, vertexID))
		return (FAIL);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (SUCCESS);
}

int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (pGraph->pVertex[fromVertexID] == NOT_USED || pGraph->pVertex[toVertexID] == NOT_USED)
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = 1;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = 1;
	return (SUCCESS);
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (pGraph->pVertex[fromVertexID] == NOT_USED || pGraph->pVertex[toVertexID] == NOT_USED)
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
	return (SUCCESS);
}

int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
	if (vertexID >= pGraph->maxVertexCount || vertexID < 0)
		return (FAIL);
	return (pGraph->pVertex[vertexID]);
}

int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (vertexID >= pGraph->maxVertexCount || vertexID < 0)
		return (FAIL);
	pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->currentVertexCount--;
	return (SUCCESS);
}

int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (fromVertexID >= pGraph->maxVertexCount || fromVertexID < 0)
		return (FAIL);
	if (toVertexID >= pGraph->maxVertexCount || toVertexID < 0)
		return (FAIL);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
	return (SUCCESS);
}

void displayArrayGraph(ArrayGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		printf("|");
		for (int j = 0; j < pGraph->maxVertexCount; j++)
		{
			if (pGraph->pVertex[i] == USED && pGraph->pVertex[j] == USED)
				printf(" %d |", pGraph->ppAdjEdge[i][j]);
			else
				printf("   |");
		}
		printf("\n");
	}
}
