#include "stack.h"

LinkedStack* createLinkedStack(void)
{
	LinkedStack *stack;

	stack = malloc(sizeof(LinkedStack));
	if (!stack)
		return (0);
	stack->currentElementCount = 0;
	stack->pTopElement = NULL;
	return (stack);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode	*to_add;

	to_add = malloc(sizeof(StackNode));
	if (!to_add || !pStack)
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
	return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	while (pStack->currentElementCount)
		free(popLS(pStack));
	free(pStack);
}

int isLinkedStackFull(LinkedStack* pStack)
{
	if (!pStack->currentElementCount)
		return (0);
	return (1);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (!pStack->currentElementCount)
		return (1);
	return (0);
}
