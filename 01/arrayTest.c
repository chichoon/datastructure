#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

int main(int argc, char *argv[]) {
	int				i;
	int				arrayCount = 0;
	ArrayList		*pList = NULL;
	ArrayListNode	*pValue = NULL;

	pList = createArrayList(6);
	if (pList != NULL)
	{
		ArrayListNode node;

		node.data = 1;
		addALElement(pList, 0, node);
		node.data = 2;
		addALElement(pList, 1, node);
		node.data = 3;
		addALElement(pList, 2, node);
		node.data = 4;
		addALElement(pList, 3, node);
		node.data = 9999;
		addALElement(pList, 0, node);
		displayArrayList(pList);
		removeALElement(pList, 0);
		displayArrayList(pList);
		arrayCount = getArrayListLength(pList);
		i = -1;
		while (++i < arrayCount)
		{
			pValue = getALElement(pList, i);
			printf("배열[%d]-%d\n", i, pValue->data);
		}
		deleteArrayList(pList);
	}

	return 0;
}
