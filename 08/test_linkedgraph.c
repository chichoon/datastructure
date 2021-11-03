#include "linkedgraph.h"

int main()
{
	LinkedGraph *graph;

	graph = createLinkedGraph(5);
	for (int i = 0; i < 4; i++) {
		addVertexLG(graph, i);
	}
	addEdgeLG(graph, 0, 1);
	// addEdgeLG(graph, 1, 0);
	addEdgeLG(graph, 0, 2);
	// addEdgeLG(graph, 2, 0);
	addEdgeLG(graph, 3, 0);
	addEdgeLG(graph, 1, 2);
	addEdgeLG(graph, 2, 3);

	displayLinkedGraph(graph);
	deleteLinkedGraph(graph);
	// system("leaks a.out");
	return (0);
}