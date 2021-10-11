#include "arraystack.h"

void	printStack(ArrayStack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->currentElementCount)
		printf("%d ", (stack->pElement + i)->data);
	printf("\n");
}

int	main(void)
{
	StackNode	element;
	ArrayStack	*stack;
	int			i;

	stack = createArrayStack(10);
	i = -1;
	while (++i < 10)
	{
		element.data = i;
		pushAS(stack, element);
	}
	printStack(stack);
	element.data = 11;
	pushAS(stack, element);
	printStack(stack);
	if (isArrayStackFull(stack))
		printf("ArrayList is full!!\n");
	printf("Pop %d\n", popAS(stack));
	printf("Pop %d\n", popAS(stack));
	printStack(stack);
	printf("Top Node: %d\n", peekAS(stack));
	printf("Pop %d\n", popAS(stack));
	printf("Pop %d\n", popAS(stack));
	printStack(stack);
	deleteArrayStack(stack);
	//system("leaks a.out");
}
