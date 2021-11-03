#include "linkedgraph.h"

LinkedGraph* createLinkedGraph(int maxVertexCount)
{
	LinkedGraph *graph;

	graph = calloc(1, sizeof(LinkedGraph));
	if (!graph)
		return (NULL);
	graph->maxVertexCount = maxVertexCount;
	graph->currentVertexCount = 0;
	graph->currentEdgeCount = 0;
	graph->graphType = GRAPH_UNDIRECTED;
	graph->ppAdjEdge = (LinkedList **)calloc(maxVertexCount, sizeof(LinkedList *));
	if (!graph->ppAdjEdge)
	{
		free (graph);
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++)
	{
		graph->ppAdjEdge[i] = createLinkedList();
		if (!graph->ppAdjEdge[i])
		{
			for (int j = 0; j < i; j++)
				deleteLinkedList(graph->ppAdjEdge[j]);
			free(graph);
			return (NULL);
		}
	}
	graph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	if (!graph->pVertex)
	{
		for (int i = 0; i < maxVertexCount; i++)
			deleteLinkedList(graph->ppAdjEdge[i]);
		free(graph);
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++)
		graph->pVertex[i] = NOT_USED;
	return (graph);
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph *graph;

	graph = calloc(1, sizeof(LinkedGraph));
	if (!graph)
		return (NULL);
	graph->maxVertexCount = maxVertexCount;
	graph->currentVertexCount = 0;
	graph->currentEdgeCount = 0;
	graph->graphType = GRAPH_DIRECTED;
	graph->ppAdjEdge = (LinkedList **)calloc(maxVertexCount, sizeof(LinkedList *));
	if (!graph->ppAdjEdge)
	{
		free (graph);
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++)
	{
		graph->ppAdjEdge[i] = createLinkedList();
		if (!graph->ppAdjEdge[i])
		{
			for (int j = 0; j < i; j++)
				deleteLinkedList(graph->ppAdjEdge[j]);
			free(graph);
			return (NULL);
		}
	}
	graph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	if (!graph->pVertex)
	{
		for (int i = 0; i < maxVertexCount; i++)
			deleteLinkedList(graph->ppAdjEdge[i]);
		free(graph);
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++)
		graph->pVertex[i] = NOT_USED;
	return (graph);
}

void deleteLinkedGraph(LinkedGraph* pGraph)
{
	free(pGraph->pVertex);
	for (int i = 0; i < pGraph->maxVertexCount; i++) {
		deleteLinkedList(pGraph->ppAdjEdge[i]);
	}
	free(pGraph->ppAdjEdge);
	free(pGraph);
}

int isEmptyLG(LinkedGraph* pGraph)
{
	if (pGraph->currentVertexCount == 0)
		return TRUE;
	else
		return FALSE;
}

int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
	if (pGraph->currentVertexCount == pGraph->maxVertexCount)
		return (FAIL);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return SUCCESS;
}

int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	ListNode element;

	if (pGraph->pVertex[fromVertexID] == NOT_USED || pGraph->pVertex[toVertexID] == NOT_USED)
		return (FAIL);
	element.id = toVertexID;
	element.weight = 1;
	addLLElement(pGraph->ppAdjEdge[fromVertexID], pGraph->ppAdjEdge[fromVertexID]->currentElementCount, element);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		element.id = fromVertexID;
		addLLElement(pGraph->ppAdjEdge[toVertexID], pGraph->ppAdjEdge[toVertexID]->currentElementCount, element);
	}
	pGraph->currentEdgeCount++;
	return (SUCCESS);
}

int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	ListNode element;

	if (pGraph->pVertex[fromVertexID] == NOT_USED || pGraph->pVertex[toVertexID] == NOT_USED)
		return (FAIL);
	element.id = toVertexID;
	element.weight = weight;
	addLLElement(pGraph->ppAdjEdge[fromVertexID], pGraph->ppAdjEdge[fromVertexID]->currentElementCount, element);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		element.id = fromVertexID;
		addLLElement(pGraph->ppAdjEdge[toVertexID], pGraph->ppAdjEdge[toVertexID]->currentElementCount, element);
	}
	pGraph->currentEdgeCount++;
	return (SUCCESS);
}

int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
	if (vertexID >= pGraph->maxVertexCount || vertexID < 0)
		return (FAIL);
	return (pGraph->pVertex[vertexID]);
}

int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	if (vertexID >= pGraph->maxVertexCount || vertexID < 0)
		return (FAIL);
	while (pGraph->ppAdjEdge[vertexID]->currentElementCount > 0)
		removeLLElement(pGraph->ppAdjEdge[vertexID], 0);
	pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->currentVertexCount--;
	return (SUCCESS);
}

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	int position;

	if (fromVertexID >= pGraph->maxVertexCount || fromVertexID < 0)
		return (FAIL);
	if (toVertexID >= pGraph->maxVertexCount || toVertexID < 0)
		return (FAIL);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		deleteGraphNode(pGraph->ppAdjEdge[toVertexID], fromVertexID);
	}
	deleteGraphNode(pGraph->ppAdjEdge[fromVertexID], toVertexID);
	pGraph->currentEdgeCount--;
	return (SUCCESS);
}

void deleteGraphNode(LinkedList* pList, int delVertexID)
{
	int	position;
	
	if (delVertexID >= pList->currentElementCount || delVertexID < 0)
		return ;
	position = findGraphNodePosition(pList, delVertexID);
	if (position < 0)
		return ;
	removeLLElement(pList, position);
}

int findGraphNodePosition(LinkedList* pList, int vertexID)
{
	ListNode	*tmp;

	if (vertexID >= pList->currentElementCount || vertexID < 0)
		return (-1);
	for (int i = 0; i < pList->currentElementCount; i++) {
		tmp = getLLElement(pList, i);
		if (tmp->id == vertexID)
			return (i);
	}
	return (-1);
}

int getEdgeCountLG(LinkedGraph* pGraph)
{
	return (pGraph->currentEdgeCount);
}

int getVertexCountLG(LinkedGraph* pGraph)
{
	return (pGraph->currentVertexCount);
}

int getMaxVertexCountLG(LinkedGraph* pGraph)
{
	return (pGraph->maxVertexCount);
}

int getGraphTypeLG(LinkedGraph* pGraph)
{
	return (pGraph->graphType);
}

void displayLinkedGraph(LinkedGraph* pGraph)
{
	ListNode *p;

	for (int i = 0; i < pGraph->maxVertexCount; i++) {
		printf("정점 [%d] 의 인접 리스트 ", i);
		p = pGraph->ppAdjEdge[i]->headerNode.pLink;
		while (p) {
			printf("-> %d ", p->id);
			p = p->pLink;
		}
		printf("\n");
	}
}