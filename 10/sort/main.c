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

	for (int i = 0; i < MAX; i++)
		data[i] = number[i];
	printf("\n====MERGE SORT====\n");
	merge_sort(data, 0, MAX - 1);
	display_list(data);
	printf("===================\n");

	int data_heap[MAX + 1];
	for (int i = 0; i < MAX; i++)
		data_heap[i + 1] = number[i];
	printf("\n=====HEAP SORT=====\n");
	heap_sort(data_heap, MAX);
	for (int i = 0; i < MAX; i++)
		printf("%d ", data_heap[i + 1]);
	printf("\n===================\n");
}
