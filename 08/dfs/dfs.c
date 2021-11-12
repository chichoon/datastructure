#include "../linkedgraph.h"
#include "linkedstack.h"

int v[8] = {0, };

void dfs(LinkedGraph *pGraph, int i)
{
	ListNode *p;
	v[i] = TRUE;
	printf("visit [%d]\n", i);

	p = pGraph->ppAdjEdge[i]->headerNode.pLink;
	while (p) {
		if (v[p->id] == FALSE)
			dfs(pGraph, p->id);
		p = p->pLink;
	}
}

int main()
{
	LinkedGraph *graph;

	graph = createLinkedGraph(8);
	for (int i = 0; i < 8; i++) {
		addVertexLG(graph, i);
	}
/*
** DFS
*/
	addEdgeLG(graph, 0, 1);
	addEdgeLG(graph, 0, 2);
	addEdgeLG(graph, 1, 3);
	addEdgeLG(graph, 1, 4);
	addEdgeLG(graph, 3, 7);
	addEdgeLG(graph, 2, 5);
	addEdgeLG(graph, 2, 6);
	addEdgeLG(graph, 4, 5);

	displayLinkedGraph(graph);
	printf("=========\n");

	int i = 0;
	dfs(graph, i);

	deleteLinkedGraph(graph);
	return (0);
}