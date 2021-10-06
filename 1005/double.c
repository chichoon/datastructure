#include "doublylist.h"
#include <stdlib.h>

DoublyList	*createDoublyList(void) //양방향 연결리스트 생성 및 초기화
{
	DoublyList	*dList; //반환해줄 DoublyList 선언

	dList = malloc(sizeof(DoublyList)); //리스트 메모리 할당
	if (!dList) //DoublyList 할당 실패 시 (malloc이 널포인터 반환했을 시)
		return (NULL); //바로 널포인터 반환 (Malloc Guard)
	dList->headerNode.pLLink = &dList->headerNode;
	dList->headerNode.pRLink = &dList->headerNode;
	//양방향 연결리스트는 마지막 노드가 맨 처음 노드를 가리키므로 (원형)
	//헤더 노드의 좌우 포인터가 자기 자신을 가리키도록 해줌
	dList->currentElementCount = 0; //DoublyList의 현재 원소 개수 0으로 초기화
	return (dList); //초기화된 리스트 반환
}

void	deleteDoublyList(DoublyList *pList) //DoublyList 삭제
{
	clearDoublyList(pList); //내부의 모든 노드를 Clear해주고 (하나하나 free)
	free(pList); //리스트 그 자체를 free
}

int	addDLElement(DoublyList *pList, int position, DoublyListNode element)
{
	int				i; //인덱스용 i 선언
	DoublyListNode	*to_add; //추가할 노드 생성
	DoublyListNode	*node; //목록을 순회하기 위한 노드 변수

	if (position > pList->currentElementCount || position < 0)
	//currentElementCount (최대 인덱스 + 1) 보다 크거나 음수일 경우 예외처리
		return (-1); //-1 반환 (에러)
	to_add = malloc(sizeof(DoublyListNode)); //추가할 노드에 메모리 할당
	if (!to_add) //할당 실패시
		return (-1); //-1 반환 (에러)
	to_add->data = element.data; //to_add 노드 (리스트에 추가할 노드) 의 data를
	//원래 넣고자 했던 Element의 data값을 넣어줌으로써 초기화
	i = -1; //인덱스 i는 -1부터 시작
	node = &pList->headerNode; //node는
	while (++i + 1 < position)
		node = node->pRLink;
	to_add->pLLink = node;
	to_add->pRLink = node->pRLink;
	node->pRLink = to_add;
	to_add->pRLink->pLLink = to_add;
	pList->currentElementCount++;
	return (0);
}

int	removeDLElement(DoublyList *pList, int position)
{
	int				i;
	DoublyListNode	*to_del;
	DoublyListNode	*node;

	if (pList->currentElementCount < position || position < 0)
		return (-1);
	i = -1;
	node = &pList->headerNode;
	while (++i + 1 < position)
		node = node->pRLink;
	to_del = node->pRLink;
	to_del->pLLink->pRLink = to_del->pRLink;
	to_del->pRLink->pLLink = to_del->pLLink;
	free(to_del);
	pList->currentElementCount--;
	return (0);
}

void clearDoublyList(DoublyList* pList)
{
	while (pList->currentElementCount > 0)
		removeDLElement(pList, 0);
}

int getDoublyListLength(DoublyList* pList)
{
	return (pList->currentElementCount);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	int				i;
	DoublyListNode	*to_find;

	if (pList->currentElementCount < position || position < 0)
		return (-1);
	to_find = &pList->headerNode;
	while (++i <= position)
		to_find = to_find->pRLink;
	return (to_find);
}

void displayDoublyList(DoublyList* pList)
{
	int				i;
	DoublyListNode	*node;

	node = &pList->headerNode;
	while (++i < pList->currentElementCount)
	{
		printf("%d ", node->data);
		node = node->pRLink;
	}
}
