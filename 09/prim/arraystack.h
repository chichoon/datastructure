#ifndef _ARRAYSTACK_
#define _ARRAYSTACK_

#include <stdlib.h>
#include <stdio.h>

typedef struct StackNodeType
{
	int data;
} StackNode;

typedef struct ArrayStackType
{
	int maxElementCount;
	int currentElementCount;
	StackNode *pElement;
} ArrayStack;

ArrayStack* createArrayStack(int maxElementCount);
int	pushAS(ArrayStack* pStack, StackNode element);
int popAS(ArrayStack* pStack);
int peekAS(ArrayStack* pStack);
void deleteArrayStack(ArrayStack *pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);

#endif
