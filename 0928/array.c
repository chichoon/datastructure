#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>

ArrayList	*createArrayList(int maxElementCount)
{
	ArrayList	*lst; //반환할 ArrayList 선언

	if (maxElementCount <= 0) //만약 최대 원소 개수가 0보다 작거나 같으면
		return (NULL); //ArrayList 제작하지 않고 널포인터 반환
	lst = malloc(sizeof(ArrayList)); //리스트 메모리 할당
	if (!lst) //ArrayList 할당 실패 시 (malloc이 널포인터 반환했을 시)
		return (NULL); //바로 널포인터 반환 (Malloc Guard)
	lst->pElement = malloc(sizeof(ArrayListNode) * maxElementCount);
	//리스트 내부의 ArrayListNode를 원소개수만큼 연속된 공간으로 할당
	if (!lst->pElement) //ArrayListNode 할당 실패 시
	{
		free(lst); //ArrayList 할당 해제
		return (NULL); //널포인터 반환 (Malloc Guard)
	}
	lst->maxElementCount = maxElementCount; //ArrayList의 최대 원소 개수 maxElementCount로 초기화
	lst->currentElementCount = 0; //ArrayList의 현재 원소 개수 0으로 초기화
	return (lst); //초기화한 리스트 반환
}

void	deleteArrayList(ArrayList *pList)
{
	if (!pList)
		return ;
	if (!pList->pElement)
	{
		free(pList);
		return ;
	}
	free(pList->pElement);
	free(pList);
}

int	isArrayListFull(ArrayList *pList)
{
	if (pList->currentElementCount == pList->maxElementCount)
		return (TRUE);
	return (FALSE);
}

int	addALElement(ArrayList *pList, int position, ArrayListNode element)
{
	int	i;

	i = pList->currentElementCount;
	if (isArrayListFull(pList) || position < 0 //ArrayList가 꽉 차거나, position이 음수일 때
		|| position > pList->currentElementCount) //position이 현재 원소 개수를 초과할 때
		return (-1); //에러 출력
	while (i > position)
	{
		(pList->pElement + i)->data = (pList->pElement + i - 1)->data;
		i--;
	}
	(pList->pElement + position)->data = element.data;
	pList->currentElementCount++;
	return (0);
}

int	removeALElement(ArrayList *pList, int position)
{
	if (position > pList->currentElementCount || position < 0)
		return (-1);
	while (++position <= pList->currentElementCount)
		*(pList->pElement + position - 1) = *(pList->pElement + position);
	pList->currentElementCount -= 1;
	return (0);
}

ArrayListNode	*getALElement(ArrayList *pList, int position)
{
	if (position >= pList->currentElementCount || position < 0)
		return (0);
	return (pList->pElement + position);
}

void displayArrayList(ArrayList* pList)
{
	int	i;

	i = -1;
	while (++i < pList->currentElementCount)
		printf("%d ", (pList->pElement + i)->data);
	printf("\n");
}

void clearArrayList(ArrayList* pList)
{
	pList->currentElementCount = 0;
}

int getArrayListLength(ArrayList* pList)
{
	return (pList->currentElementCount);
}
