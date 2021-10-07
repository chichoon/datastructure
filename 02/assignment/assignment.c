#include "linkedlist.h"
#include <stdio.h>

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

void	printAlgebra(LinkedList *pList)
{
	int			i;
	ListNode	*node;

	i = -1;
	node = &pList->headerNode;
	while (++i + 1 < pList->currentElementCount)
	{
		node = node->pLink;
		printf("%dx^%d + ", node->data, i);
	}
	node = node->pLink;
	printf("%dx^%d", node->data, i);
	printf("\n");
}

void reverseLinkedList(LinkedList *pList)
{
	ListNode	*node_tmp;
	ListNode	*node_prev;
	ListNode	*node_now;

	if (!pList)
		return ;
	node_prev = pList->headerNode.pLink;
	node_now = pList->headerNode.pLink->pLink;
	node_prev->pLink = NULL;
	while (node_now)
	{
		node_prev = node_now;
		node_now = node_tmp;
		node_tmp = node_now->pLink;
		node_now->pLink = node_prev;
	}

}

LinkedList	*alge_plus(LinkedList *pListA, LinkedList *pListB)
{
	LinkedList	*pList;
	ListNode	*nodeA;
	ListNode	*nodeB;
	ListNode	node_temp;
	int			i;

	if (!pListA || !pListB)
		return (0);
	pList = createLinkedList();
	if (!pList)
		return (0);
	nodeA = pListA->headerNode.pLink;
	nodeB = pListB->headerNode.pLink;
	i = 0;
	while (nodeA || nodeB)
	{
		if (!nodeA)
		{
			addLLElement(pList, i, *nodeB);
			nodeB = nodeB->pLink;
		}
		else if (!nodeB)
		{
			addLLElement(pList, i, *nodeA);
			nodeA = nodeA->pLink;
		}
		else
		{
			node_temp.data = nodeA->data + nodeB->data;
			addLLElement(pList, i, node_temp);
			nodeA = nodeA->pLink;
			nodeB = nodeB->pLink;
		}
		i++;
	}
	return (pList);
}

int	main(void)
{
	LinkedList	*pListA;
	LinkedList	*pListB;
	LinkedList	*pListC;
	ListNode	elem;

	pListA = createLinkedList();
	pListB = createLinkedList();

	elem.data = 0;
	addLLElement(pListA, 0, elem);
	elem.data = 0;
	addLLElement(pListA, 1, elem);
	elem.data = 2;
	addLLElement(pListA, 2, elem);
	elem.data = 0;
	addLLElement(pListA, 3, elem);
	elem.data = 0;
	addLLElement(pListA, 4, elem);
	elem.data = 4;
	addLLElement(pListA, 5, elem);
	elem.data = 6;
	addLLElement(pListA, 6, elem);
	printAlgebra(pListA);

	elem.data = 4;
	addLLElement(pListB, 0, elem);
	elem.data = 0;
	addLLElement(pListB, 1, elem);
	elem.data = 3;
	addLLElement(pListB, 2, elem);
	elem.data = 0;
	addLLElement(pListB, 3, elem);
	elem.data = 2;
	addLLElement(pListB, 4, elem);
	elem.data = 1;
	addLLElement(pListB, 5, elem);
	printAlgebra(pListB);

	pListC = alge_plus(pListA, pListB);
	printAlgebra(pListC);

	reverseLinkedList(pListC);
	printLinkedList(pListC);
}
