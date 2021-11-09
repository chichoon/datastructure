#include "bfs.h"

void	bfs(ArrayGraph *graph)
{
	ArrayQueue		*queue;
	ArrayQueueNode	element;
	int				headerNode;
	int				u;
	int				*visited;

	queue = createArrayQueue(graph->maxVertexCount);
	visited = malloc(sizeof(int) * graph->maxVertexCount);
	if (!queue || !visited)
		return ;
	for (int i = 0; i < graph->maxVertexCount; i++)
		visited[i] = 0;
	headerNode = 1;
	visited[headerNode] = 1;
	element.data = headerNode;
	enQueue(queue, element);
	printf("Traversed: %d\n", element.data);
	while (!isQueueEmpty(queue))
	{
		u = deQueue(queue);
		for (int i = 0; i < graph->maxVertexCount; i++)
		{
			if (graph->ppAdjEdge[u][i] == 1 && visited[i] == 0)
			{
				printf("Traversed: %d\n", i);
				visited[i] = 1;
				element.data = i;
				enQueue(queue, element);
			}
		}
	}
	deleteQueue(queue);
	free(visited);
}
