#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void	printLinkedList(LinkedList *pList)
{
	int			i;
	ListNode	*node;

	i = -1;
	node = &pList->headerNode;
	while (++i < pList->currentElementCount)
	{
		node = node->pLink;
		printf("%d ", node->data);
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	int			i;
	LinkedList	*pList;
	ListNode	node;

	pList = createLinkedList();
	if (pList != NULL)
	{
		node.data = 5;
		addLLElement(pList, 1, node);
		node.data = 7;
		addLLElement(pList, 1, node);
		node.data = 3;
		addLLElement(pList, 1, node);
		printLinkedList(pList);
		removeLLElement(pList, 2);
		printLinkedList(pList);
	}
}
