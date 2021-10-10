#ifndef _LINKEDSTACK_
#define _LINKEDSTACK_

#include <stdlib.h>
#include <stdio.h>

typedef struct StackNodeType
{
	int	data;
	struct StackNodeType *next;
} StackNode;

typedef struct LinkedStackType
{
	int maxElementCount;
	int currentElementCount;	// 현재 원소의 개수
	StackNode* pTopElement;		// Top 노드의 포인터
} LinkedStack;

LinkedStack* createLinkedStack(int maxElementCount);
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

#endif
