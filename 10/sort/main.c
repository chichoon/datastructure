#include "sort.h"

int	main(void)
{
	int	number[MAX];
	int	data[MAX];

	for (int i = 0; i < MAX; i++)
		number[i]  = rand() % 10000;
	for (int i = 0; i < MAX; i++)
		data[i] = number[i];

	printf("\n====BUBBLE SORT====\n");
	bubble_sort(data, MAX);
	for (int i = 0; i < MAX; i++)
		printf("%d ", data[i]);
	printf("\n===================\n");
	for (int i = 0; i < MAX; i++)
		data[i] = number[i];
	printf("\n====INSERT SORT====\n");
	insert_sort(data, MAX);
	for (int i = 0; i < MAX; i++)
		printf("%d ", data[i]);
	printf("\n===================\n");
}
