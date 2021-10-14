#ifndef _MAZE_
#define _MAZE_

#include <stdlib.h>
#include <stdio.h>

typedef struct StackNodeType
{
	int	positionX;
	int	positionY;
	struct StackNodeType *next;
} StackNode;

typedef struct LinkedStackType
{
	int	currentElementCount;
	StackNode	*pTopElement;
} LinkedStack;

LinkedStack *createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);


#endif
