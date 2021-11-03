#include "linkedlist.h"

LinkedList* createLinkedList(void)
{
	LinkedList* list;

	list = (LinkedList *)malloc(sizeof(LinkedList));
	list->currentElementCount = 0;
	list->headerNode.pLink = NULL;
	return (list);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode *new;
	ListNode *cur;

	new = (ListNode *)malloc(sizeof(ListNode));
	new->id = element.id;
	new->weight = element.weight;
	if (position == 0)
	{
		cur = &pList->headerNode;
	}
	else {
		cur = getLLElement(pList, position - 1);
		if (cur == NULL)
			return (1);
	}
	new->pLink = cur->pLink;
	cur->pLink = new;
	pList->currentElementCount++;
	return (0);
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode *prev;
	ListNode *tmp;

	if (!(-1 < position && position < pList->currentElementCount))
		return (1);
	if (position == 0)
	{
		tmp = pList->headerNode.pLink;
		pList->headerNode.pLink = tmp->pLink;
		free(tmp);
	}
	else {
		prev = getLLElement(pList, position - 1);
		tmp = prev->pLink->pLink;
		free(prev->pLink);
		prev->pLink = tmp;
	}
	pList->currentElementCount--;
	return (0);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode *ret;

	if (!(-1 < position && position < pList->currentElementCount))
		return NULL;
	ret = pList->headerNode.pLink;
	for (int i = 0; i < position; i++){
		ret = ret->pLink;
	}
	return (ret);
}

void clearLinkedList(LinkedList* pList)
{
  ListNode *next;
  ListNode *tmp;

	next = pList->headerNode.pLink;
	for (int i = 0; i < pList->currentElementCount; i++)
	{
		tmp = next->pLink;
		free(next);
		next = tmp;
	}
	pList->headerNode.pLink = NULL;
	pList->currentElementCount = 0;
}

int getLinkedListLength(LinkedList* pList)
{
	return(pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
  clearLinkedList(pList);
  free(pList);
}