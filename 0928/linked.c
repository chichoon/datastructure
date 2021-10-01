#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

LinkedList	*createLinkedList(void)
{
	LinkedList	*lst;

	lst = malloc(sizeof(LinkedList));
	if (!lst)
		return (0);
	lst->currentElementCount = 0;
	return (lst);
}

int	addLLElement(LinkedList *pList, int position, ListNode element)
{
	int			i;
	ListNode	*node;

	if (pList->currentElementCount + 1 < position
		|| position < 0)
		return (-1);
	i = -1;
	node = &pList->headerNode;
	while (++i + 1 < position)
		node = node->pLink;
	element.pLink = node->pLink;
	node->pLink = &element;
	return (0);
}

int	removeLLElement(LinkedList *pList, int position)
{
	int			i;
	ListNode	*node;
	ListNode	*to_del;

	if (pList->currentElementCount < position
		|| position < 0)
		return (-1);
	i = -1;
	node = &pList->headerNode;
	while (++i + 1 < position)
		node = node->pLink;
	to_del = node->pLink;
	node->pLink = node->pLink->pLink;
	free(to_del);
	return (0);
}

ListNode	*getLLElement(LinkedList *pList, int position)
{
	int			i;
	ListNode	*node;

	if (pList->currentElementCount < position
		|| position < 0)
		return (-1);
	i = -1;
	node = &pList->headerNode;
	while (++i < position)
		node = node->pLink;
	return (node);
}

void	clearLinkedList(LinkedList *pList)
{
	int			i;
	ListNode	*node;
	ListNode	*to_del;

	i = -1;
	node = &pList->headerNode;
	to_del = node->pLink;
	while (++i < pList->currentElementCount)
		removeLLElement(pList, i);
}

int	getLinkedListLength(LinkedList *pList)
{
	return (pList->currentElementCount);
}

void	deleteLinkedList(LinkedList *pList)
{
	clearLinkedList(pList);
	free(pList);
}
