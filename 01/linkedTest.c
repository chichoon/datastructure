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
		i = -1;
		while (++i < 10)
		{
			node.data = i;
			addLLElement(pList, 0, node);
		}
		printLinkedList(pList);
		removeLLElement(pList, 2);
		printLinkedList(pList);
		printf("1st element: %d\n", getLLElement(pList, 1)->data);
		printf("list length: %d\n", getLinkedListLength(pList));
		clearLinkedList(pList);
		printf("list length: %d\n", getLinkedListLength(pList));
		deleteLinkedList(pList);
	}
}
