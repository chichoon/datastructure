#include "linkedstack.h"
#include <stdio.h>
#include <stdlib.h>

LinkedStack* createLinkedStack()
{
	LinkedStack *stack;

	stack = (LinkedStack *)malloc(sizeof(LinkedStack));
	stack->currentElementCount = 0;
	stack->pTopElement = NULL;
	return stack;
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode *new;

	new = (StackNode *)malloc(sizeof(StackNode));
	new->data = element.data;
	if (isLinkedStackEmpty(pStack) == TRUE) {
		pStack->pTopElement = new;
		new->pLink = NULL;
	} else {
		new->pLink = pStack->pTopElement;
		pStack->pTopElement = new;
	}
	pStack->currentElementCount++;
	return TRUE;
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode *tmp;

	tmp = pStack->pTopElement;
	pStack->pTopElement = tmp->pLink;
	tmp->pLink = NULL;
	pStack->currentElementCount--;
	return (tmp);
}

StackNode* peekLS(LinkedStack* pStack)
{
	if (isLinkedStackEmpty(pStack) == TRUE)
		return NULL;
	return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	StackNode *tmp;

	tmp = pStack->pTopElement;
	for (int i = 0; i < pStack->currentElementCount - 1; i++)
	{
		pStack->pTopElement = pStack->pTopElement->pLink;
		free(tmp);
		tmp = pStack->pTopElement;
	}
	free(pStack);
}

// int isLinkedStackFull(LinkedStack* pStack)
// {
// 	//FULL이 있을  수  있나...?
// }

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (pStack->currentElementCount == 0)
		return TRUE;
	return FALSE;
}