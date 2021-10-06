#include "doublylist.h"
#include <stdlib.h>

DoublyList	*createDoublyList(void)
{
	DoublyList	*dList;

	dList = malloc(sizeof(DoublyList));
	if (!dList)
		return (NULL);
	dList->headerNode.pLLink = &dList->headerNode;
	dList->headerNode.pRLink = &dList->headerNode;
	dList->currentElementCount = 0;
	return (dList);
}

void	deleteDoublyList(DoublyList *pList)
{
	clearDoublyList(pList);
	free(pList);
}

int	addDLElement(DoublyList *pList, int position, DoublyListNode element)
{
	int				i;
	DoublyListNode	*to_add;
	DoublyListNode	*node;

	if (pList->currentElementCount + 1 < position || position < 0)
		return (-1);
	to_add = malloc(sizeof(DoublyListNode));
	if (!to_add)
		return (-1);
	to_add->data = element.data;
	i = -1;
	node = &pList->headerNode;
	while (++i + 1 < position)
		node = node->pRLink;
	to_add->pLLink = node;
	to_add->pRLink = node->pRLink;
	node->pRLink = to_add;
	to_add->pRLink->pLLink = to_add;
	pList->currentElementCount++;
	return (0);
}

int	removeDLElement(DoublyList *pList, int position)
{
	int				i;
	DoublyListNode	*to_del;
	DoublyListNode	*node;

	if (pList->currentElementCount < position || position < 0)
		return (-1);
	i = -1;
	node = &pList->headerNode;
	while (++i + 1 < position)
		node = node->pRLink;
	to_del = node->pRLink;
	to_del->pLLink->pRLink = to_del->pRLink;
	to_del->pRLink->pLLink = to_del->pLLink;
	free(to_del);
	pList->currentElementCount--;
	return (0);
}
void clearDoublyList(DoublyList* pList)
{

}
int getDoublyListLength(DoublyList* pList);
DoublyListNode* getDLElement(DoublyList* pList, int position);
void displayDoublyList(DoublyList* pList);
