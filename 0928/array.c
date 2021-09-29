#include "arraylist.h"
#include <stdlib.h>

ArrayList	*createArrayList(int maxElementCount)
{
	ArrayList	*lst;

	lst = malloc(sizeof(ArrayList) * maxElementCount);
	if (!lst)
		return (0);
	return (lst);
}

void	deleteArrayList(ArrayList *pList)
{
	free()
}
