#include "arraylist.h"
#include <stdlib.h>

ArrayList	*createArrayList(int maxElementCount)
{
	ArrayList	*lst;

	lst = malloc(sizeof(ArrayList));
	if (!lst)
		return (0);
	lst->pElement = malloc(sizeof(ArrayListNode) * maxElementCount);
	if (!lst->pElement)
	{
		free(lst);
		return (0);
	}
	lst->maxElementCount = maxElementCount;
	lst->currentElementCount = 0;
	return (lst);
}

void	deleteArrayList(ArrayList *pList)
{
	free()
}

int isArrayListFull(ArrayList* pList)
{

}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{

}

int removeALElement(ArrayList* pList, int position)
{

}

ArrayListNode* getALElement(ArrayList* pList, int position)
{

}

void displayArrayList(ArrayList* pList)
{

}

void clearArrayList(ArrayList* pList)
{

}

int getArrayListLength(ArrayList* pList)
{

}
