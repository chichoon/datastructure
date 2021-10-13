#include "linkedstack.h"

LinkedStack* createLinkedStack(int maxElementCount)
{
	LinkedStack *stack;

	if (maxElementCount <= 0)
		return (NULL);
	stack = malloc(sizeof(LinkedStack));
	if (!stack)
		return (NULL);
	stack->maxElementCount = maxElementCount;
	stack->currentElementCount = 0;
	stack->pTopElement = NULL;


	return (stack);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode	*to_add;

	if (!pStack || isLinkedStackFull(pStack))

		return (-1);
	to_add = malloc(sizeof(StackNode));
	if (!to_add)
		return (-1);
	to_add->data = element.data;
	to_add->next = pStack->pTopElement;
	pStack->pTopElement = to_add;

	pStack->currentElementCount++;
	return (0);
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode	*to_return;

	if (!pStack)
		return (NULL);
	to_return = pStack->pTopElement;
	pStack->pTopElement = to_return->next;
	pStack->currentElementCount--;
	return (to_return);


}

StackNode* peekLS(LinkedStack* pStack)
{
	if (!pStack)
		return (NULL);
	return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	if (!pStack)
		return ;
	while (pStack->currentElementCount)
		free(popLS(pStack));
	free(pStack);
}

int isLinkedStackFull(LinkedStack* pStack)
{
	if (!pStack)
		return (-1);
	if (pStack->currentElementCount == pStack->maxElementCount)
		return (1);
	return (0);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (!pStack)
		return (-1);
	if (!pStack->currentElementCount)
		return (1);
	return (0);
}
