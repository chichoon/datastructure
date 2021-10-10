#include "stack.h"

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

	stack = createLinkedStack();
	i = -1;
	while (++i < 10)
	{
		element.data = i;
		pushLS(stack, element);
	}
	printStack(stack);
	free(popLS(stack));
	free(popLS(stack));
	printStack(stack);
	printf("Top Node: %d\n", peekLS(stack)->data);
	free(popLS(stack));
	free(popLS(stack));
	printStack(stack);
	deleteLinkedStack(stack);
	system("leaks a.out");
}
