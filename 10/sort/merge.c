#include "sort.h"

int arrTemp[MAX];

static void merge(int *arr, int leftMost, int rightMost)
{
	int leftIdx, rightIdx, midIdx;
	int i;

	leftIdx = leftMost;
	midIdx = (leftMost + rightMost) / 2;
	rightIdx = midIdx + 1;
	i = leftMost;

	while (leftIdx <= midIdx && rightIdx <= rightMost)
	{
		if (arr[leftIdx] <= arr[rightIdx])
			arrTemp[i] = arr[leftIdx++];
		else
			arrTemp[i] = arr[rightIdx++];
		i++;
	}
	if (i > midIdx)
	{
		for (int j = rightIdx; j <= rightMost; j++)
			arrTemp[i++] = arr[j];
	}
	else
	{
		for (int j = leftIdx; j <= midIdx; j++)
			arrTemp[i++] = arr[j];
	}
	for (int j = leftMost; j <= midIdx; j++)
	{
		arr[j] = arrTemp[j];
	}
}

void merge_sort(int *arr, int leftMost, int rightMost)
{
	int midIdx;

	if (leftMost < rightMost)
	{
		midIdx = (leftMost + rightMost) / 2;
		merge_sort(arr, leftMost, midIdx);
		merge_sort(arr, midIdx + 1, rightMost);
		merge(arr, leftMost, rightMost);
	}
}
