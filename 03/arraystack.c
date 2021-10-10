#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount)
{
	ArrayStack	*stack;

	if (maxElementCount <= 0)
		return (NULL);
	stack = malloc(sizeof(ArrayStack));
	if (!stack)
		return (NULL);
	stack->pElement = malloc(sizeof(StackNode) * maxElementCount);
	if (!stack->pElement)
	{
		free(stack);
		return (NULL);
	}
	stack->maxElementCount = maxElementCount;
	stack->currentElementCount = 0;
	return (stack);
}

int	pushAS(ArrayStack* pStack, StackNode element)
{
	int i;

	i = pStack->currentElementCount;
	if (!pStack || isArrayStackFull(pStack))
		return (-1);
	while (i > 0)
	{
		(pStack->pElement + i)->data = (pStack->pElement + i - 1)->data;
		i--;
	}
	(pStack->pElement)->data = element.data;
	pStack->currentElementCount++;
	return (0);
}

int popAS(ArrayStack* pStack)
{
	int i;
	int elem_return;

	i = 0;
	elem_return = pStack->pElement->data;
	if (!pStack)
		return (0);
	while (++i <= pStack->currentElementCount)
		*(pStack->pElement + i - 1) = *(pStack->pElement + i);
	pStack->currentElementCount--;
	return (elem_return);
}

int peekAS(ArrayStack* pStack)
{
	if (!pStack)
		return (0);
	return (pStack->pElement->data);
}

void deleteArrayStack(ArrayStack *pStack)
{
	if (!pStack)
		return ;
	free(pStack->pElement);
	free(pStack);
}

int isArrayStackFull(ArrayStack* pStack)
{
	if (!pStack)
		return (-1);
	if (pStack->currentElementCount == pStack->maxElementCount)
		return (1);
	return (0);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
	if (!pStack)
		return (-1);
	if (!pStack->currentElementCount)
		return (1);
	return (0);
}
