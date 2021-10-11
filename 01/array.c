#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>

ArrayList	*createArrayList(int maxElementCount) //ArrayList 생성 및 초기화
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
		free(lst); //ArrayList free
		return (NULL); //널포인터 반환 (Malloc Guard)
	}
	lst->maxElementCount = maxElementCount; //ArrayList의 최대 원소 개수 maxElementCount로 초기화
	lst->currentElementCount = 0; //ArrayList의 현재 원소 개수 0으로 초기화
	return (lst); //초기화한 리스트 반환
}

void	deleteArrayList(ArrayList *pList) //ArrayList 삭제
{
	if (!pList) //입력값으로 받아온 ArrayList가 존재하지 않을 때
		return ; //아무일도 하지 않고 함수 종료
	if (!pList->pElement) //입력값으로 받아온 ArrayList 내부에 pElement가 존재하지 않을 때
	{
		free(pList); //ArrayList만 free 해준 후
		return ; //아무일도 하지 않고 함수 종료
	}
	free(pList->pElement); //pElement (원소들이 들어가는 영역) free
	free(pList); //리스트 그 자체를 free
}

int	isArrayListFull(ArrayList *pList) //ArrayList 꽉 찼는지 검사
{
	if (pList->currentElementCount == pList->maxElementCount) //ArrayList 내부 원소 개수가 최대 원소 개수와 같으면
		return (TRUE); //True (참) 반환
	return (FALSE); //아니면 False 반환
}

int	addALElement(ArrayList *pList, int position, ArrayListNode element) //ArrayList에 원소 추가
{
	int	i; //인덱스용 i 선언

	i = pList->currentElementCount; //i는 현재 원소의 개수부터 시작 (인덱스 최대값 + 1)
	if (isArrayListFull(pList) || position < 0 //ArrayList가 꽉 차거나, position이 음수일 때
		|| position > pList->currentElementCount) //position이 현재 원소 개수를 초과할 때
		//(배열 내에서도 값이 연속해서 들어와야 하기 때문에 CurrentElementCount 범위를 넘어설 경우
		//중간에 공백이 생겨버리므로 에러처리가 됨)
		//또는 position이 음수일때, pList가 꽉 찼을 때 예외처리
		return (-1); //-1 반환 (에러)
	while (i > position) //position 직후까지
	{ //예시: currentElementCount가 5고 position이 3이면, 3, 4번 인덱스의 원소만 4, 5번으로 이동
		(pList->pElement + i)->data = (pList->pElement + i - 1)->data;
		//한 칸 뒤의 공간으로 앞의 원소를 밀어줌 (position 인덱스에 빈 칸을 만들어 원소를 넣기 위함)
		i--; //i 줄여가면서 배열의 왼쪽 (인덱스가 작은 쪽) 으로 이동
	}
	(pList->pElement + position)->data = element.data; //position 인덱스에 공백을 만들었다면
	//해당 자리에 원래 넣고자 했던 Element의 data값을 넣어줌
	//(ArrayListNode element를 그대로 넣으면 스택 값이라 함수 밖에서 메모리가 깨짐)
	pList->currentElementCount++; //원소를 추가했으므로 원소 카운트 (currentElementCount) 1 더해줌
	return (0); //함수 반환 (정상작동이므로 0)
}

int	removeALElement(ArrayList *pList, int position) //ArrayList에서 원소 제거
{
	if (position > pList->currentElementCount || position < 0)
	//position이 currentElementCount보다 크거나 (원소가 존재하지 않는 구역) position이 음수일 때
		return (-1); //-1 반환 (에러)
	while (++position < pList->currentElementCount) //position부터 currentElementCount까지
	//(position 인덱스에 있던 원소를 지우고 그 뒤에 위치한 원소들을 한 칸씩 앞으로 당겨주기 위함)
		*(pList->pElement + position - 1) = *(pList->pElement + position);
		//addALElement와 반대 방식으로 동작한다고 생각하면 됨
	pList->currentElementCount -= 1; //원소를 제거했으므로 원소 카운트 (currentElementCount) 1 빼줌
	return (0); //함수 반환 (정상작동이므로 0)
}

ArrayListNode	*getALElement(ArrayList *pList, int position) //ArrayList에서 원소 하나 빼오기
{
	if (position >= pList->currentElementCount || position < 0)
	//position이 currentElementCount보다 크거나 (원소가 존재하지 않는 구역) position이 음수일 때
		return (NULL); //널포인트 반환 (원소찾기 실패)
	return (pList->pElement + position); //pElement에서 position만큼 떨어진 공간의 노드 반환
	//배열로 접근 대신 포인터로 접근하는 방식
}

void displayArrayList(ArrayList* pList) //ArrayList 출력
{
	int	i; //인덱스 변수 선언

	i = -1; //-1부터 시작한 후 전위연산을 통해 0으로 만들어줌
	while (++i < pList->currentElementCount) //currentElementCount 전까지
		printf("%d ", (pList->pElement + i)->data); //인덱스 i에 해당하는 원소를 반복해서 출력
	printf("\n"); //마지막에 개행은 그냥 깔끔해보이려고
}

void clearArrayList(ArrayList* pList) //배열 비우기
{
	pList->currentElementCount = 0; //원소 값 초기화 필요 없이 currentElementCount만 0으로 초기화
	//어차피 원소를 추가할 때 값이 덮어씌워지므로 처음부터 초기화는 필요가 없었다
}

int getArrayListLength(ArrayList* pList) //배열 길이 반환
{
	return (pList->currentElementCount); //currentElementCount 반환
}
