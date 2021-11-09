#include "bfs.h"

int	main()
{
	ArrayGraph *graph;

	graph = createArrayGraph(15);
	for (int i = 0; i < 6; i++) {
		addVertexAG(graph, 2 * i + 1);
	}
	addEdgeAG(graph, 1, 5);
	addEdgeAG(graph, 1, 3);
	addEdgeAG(graph, 5, 9);
	addEdgeAG(graph, 3, 11);
	addEdgeAG(graph, 3, 7);
	/*
			  1
			/  \
			5  3
		   /  /\
		  9  11 7
	*/
	displayArrayGraph(graph);

	bfs(graph);
}
