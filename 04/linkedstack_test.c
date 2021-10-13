#include "linkedstack.h"

void	printStack(LinkedStack *stack)
{
	StackNode	*node;

	node = stack->pTopElement;
	printf("Top Node: %d\n", node->data);
	while (node)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

int	main(void)
{
	StackNode	element;
	LinkedStack	*stack;
	int			i;

	stack = createLinkedStack(10);
	i = -1;
	while (++i < 10)
	{
		element.data = i;
		pushLS(stack, element);
	}
	printStack(stack);
	element.data = 11;
	pushLS(stack, element);
	printStack(stack);
	if (isLinkedStackFull(stack))
		printf("LinkedList is full!!\n");
	free(popLS(stack));
	free(popLS(stack));
	printStack(stack);
	printf("Top Node: %d\n", peekLS(stack)->data);
	free(popLS(stack));
	free(popLS(stack));
	printStack(stack);
	deleteLinkedStack(stack);
	//system("leaks a.out");
}
