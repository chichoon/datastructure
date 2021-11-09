#include "bfs.h"

int	main()
{
	ArrayGraph *graph;

	graph = createArrayGraph(6);
	for (int i = 0; i < 6; i++) {
		addVertexAG(graph, i);
	}
	addEdgeAG(graph, 0, 1);
	addEdgeAG(graph, 0, 2);
	addEdgeAG(graph, 1, 3);
	addEdgeAG(graph, 2, 4);
	addEdgeAG(graph, 2, 5);
	displayArrayGraph(graph);

	bfs(graph);
}
