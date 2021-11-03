#include "arraygraph.h"

int main()
{
	ArrayGraph *graph;

	// 0 - 3
	// | 
	// 1 - 2

	graph = createArrayDirectedGraph(5);
	for (int i = 0; i < 4; i++) {
		addVertexAG(graph, i);
	}
	addEdgeAG(graph, 0, 1);
	addEdgeAG(graph, 0, 2);
	addEdgeAG(graph, 0, 3);
	addEdgeAG(graph, 1, 2);
	addEdgeAG(graph, 2, 3);
	displayArrayGraph(graph);
	removeEdgeAG(graph, 0, 3);
	printf("removed edge 0 -> 3\n");
	displayArrayGraph(graph);
	deleteArrayGraph(graph);
	return (0);
}