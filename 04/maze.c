#include "maze.h"

LinkedStack *createLinkedStack(void)
{
	LinkedStack	*stack;

	stack = malloc(sizeof(LinkedStack));
	if (!stack)
		return (NULL);
	stack->currentElementCount = 0;
	stack->pTopElement = NULL;
	return (stack);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode	*to_add;

	if (!pStack)
		return (-1);
	to_add = malloc(sizeof(StackNode));
	if (!to_add)
		return (-1);
	to_add->positionX = element.positionX;
	to_add->positionY = element.positionY;
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

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (!pStack)
		return (-1);
	if (!pStack->currentElementCount)
		return (1);
	return (0);
}


void	pushDirection(int mymaze[8][8], LinkedStack *pStack, int x, int y)
{
	StackNode	element;

	if (x >= 8 || y >= 8 || x < 0 || y < 0)
		return ;
	if (mymaze[x][y] != 1 && mymaze[x][y] != 2)
	{
		element.positionX = x;
		element.positionY = y;
		pushLS(pStack, element);
	}
}

/*
void	printStack(LinkedStack *stack)
{
	StackNode	*node;

	node = stack->pTopElement;
	printf("(%d %d)", peekLS(stack)->positionX, peekLS(stack)->positionY);
	while (node)
	{
		printf(" <- (%d, %d)", node->positionX, node->positionY);
		node = node->next;
	}
	printf("\n");
}
*/

void	printMaze(int mymaze[8][8], LinkedStack *stack)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < 8)
		{
			if (mymaze[i][j] == 1)
				printf("⬛️");
			else if (mymaze[i][j] == 0)
				printf("⬜️");
			else if (mymaze[i][j] == 2)
				printf("🟥");
		}
		printf("\n");
	}
}

void	getMazeRoute(int mymaze[8][8], int startPos[2], int endPos[2])
{
	LinkedStack	*stack;
	int			x;
	int			y;

	stack = createLinkedStack();
	if (!stack)
		return ;
	x = startPos[0];
	y = startPos[1];
	mymaze[x][y] = 2;
	printf("(%d %d)", x, y);
	while (x != endPos[0] && y != endPos[1])
	{
		pushDirection(mymaze, stack, x, y - 1);
		pushDirection(mymaze, stack, x + 1, y);
		pushDirection(mymaze, stack, x, y + 1);
		pushDirection(mymaze, stack, x - 1, y);
		if (isLinkedStackEmpty(stack))
		{
			printf("Failed to find route");
			return ;
		}
		else
		{
			x = peekLS(stack)->positionX;
			y = peekLS(stack)->positionY;
			mymaze[x][y] = 2;
			printf(" -> (%d, %d)", x, y);
			free(popLS(stack));
		}
	}
	printf("\n");
	printMaze(mymaze, stack);
	deleteLinkedStack(stack);
}

int	main(void)
{
	int start[2] = {0, 0};
	int end[2] = {7, 7};

	int myMaze[8][8] = {
		{0, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 0}
	};
	getMazeRoute(myMaze, start, end);
}
