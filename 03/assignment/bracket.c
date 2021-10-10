#include "../linkedstack.h"

int	checkSymbol(LinkedStack *stack, char c)
{
	StackNode	*pop_node;

	pop_node = popLS(stack);
	if ((c == '}' && pop_node->data == '{')
		|| (c == ']' && pop_node->data == '[')
		|| (c == ')' && pop_node->data == '('))
	{
		free(pop_node);
		return (1);
	}
	return (0);
}

int	checkBracketMatching(char *str)
{
	LinkedStack	*stack;
	StackNode	element;
	int			result;

	stack = createLinkedStack(10);
	if (!stack || !str)
		return (0);
	result = 1;
	while (*str && result != 0)
	{
		if (*str == '{' || *str == '(' || *str == '[')
		{
			element.data = *str;
			pushLS(stack, element);
		}
		else if (*str == '}' || *str == ')' || *str == ']')
			if (!checkSymbol(stack, *str))
				result = 0;
		str++;
	}
	if (!isLinkedStackEmpty(stack))
		result = 0;
	deleteLinkedStack(stack);
	return (result);
}

int	main(void)
{
	char *str1 = "((A*B)/C)-{(D+E)&&(F-G)}";
	char *str2 = "((A*B)/C-{(D+E)&&(F-G))}";

	if (checkBracketMatching(str1))
		printf("%s\t=> ALL BRACKET MATCHING!\n", str1);
	else
		printf("%s\t=> BRACKET FAILED!!!!!\n", str1);

	if (checkBracketMatching(str2))
		printf("%s\t=> ALL BRACKET MATCHING!\n", str2);
	else
		printf("%s\t=> BRACKET FAILED!!!!!\n", str2);
}

