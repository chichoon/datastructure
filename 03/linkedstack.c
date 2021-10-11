#include "linkedstack.h"

LinkedStack* createLinkedStack(int maxElementCount) //연결리스트 스택 생성 및 초기화
{
	LinkedStack *stack; //반환할 스택 포인터 지정

	if (maxElementCount <= 0) //maxElementCount가 음수이거나 0이면
		return (NULL); //널포인터 반환
	stack = malloc(sizeof(LinkedStack)); //스택에 대한 메모리 할당
	if (!stack) //할당 실패시
		return (NULL); //널포인터 반환
	stack->maxElementCount = maxElementCount; //스택의 최대 원소 개수를 maxElementCount로 지정
	stack->currentElementCount = 0; //스택의 현재 원소 개수를 0으로 지정
	stack->pTopElement = NULL; //스택의 현재 최상위 노드 (top) 을 널포인터로 지정
	//push를 통해 노드를 추가할 때 next 포인터를 조정해 줌으로써
	//맨 아래 (bottom) 의 원소는 NULL을 가리키도록 하기 위함
	return (stack); //스택 포인터 반환
}

int pushLS(LinkedStack* pStack, StackNode element) //스택에 값 Push
{
	StackNode	*to_add; //추가할 노드 포인터 선언

	if (!pStack || isLinkedStackFull(pStack))
	//스택이 존재하지 않거나, 스택이 꽉 찼을 경우
		return (-1); //-1 반환
	to_add = malloc(sizeof(StackNode)); //Push할 노드에 메모리 공간 할당
	if (!to_add) //노드 할당 실패 시
		return (-1); //-1 반환
	to_add->data = element.data; //Push할 노드에 데이터 값 지정
	to_add->next = pStack->pTopElement; //노드의 다음 포인터를 현재 맨 위에 위치한 노드로 지정
	pStack->pTopElement = to_add; //스택의 가장 위 노드 (top) 을 추가할 노드 to_add로 지정
	//이를 통해 to_add가 스택의 맨 위에 위치하도록 조정 완료
	pStack->currentElementCount++; //현재 스택의 원소의 개수 1 추가
	return (0); //성공했으므로 0 반환
}

StackNode* popLS(LinkedStack* pStack) //스택에서 값 Pop
{
	StackNode	*to_return; //반환할 노드 포인터 변수 선언

	if (!pStack) //스택이 존재하지 않을 경우
		return (NULL); //널 포인터 반환
	to_return = pStack->pTopElement; //가장 위에 있는 노드 주소값을 반환할 노드 포인터에 저장
	pStack->pTopElement = to_return->next; //가장 위의 노드를 그 다음 노드로 지정
	pStack->currentElementCount--; //원소 개수 1 감소
	return (to_return); //노드 그대로 반환
	//노드 포인터를 반환하는 만큼 이를 사용자가 이용하게 될 가능성이 있으므로,
	//굳이 메모리 해제를 해 주지 않았다 (사용자의 몫)
}

StackNode* peekLS(LinkedStack* pStack) //스택 값 Peek
{
	if (!pStack) //스택이 유효하지 않을 경우
		return (NULL); //오류값 (0) 반환
	return (pStack->pTopElement); //top 노드 주소값 그대로 반환
}

void deleteLinkedStack(LinkedStack* pStack) //스택 삭제
{
	if (!pStack) //스택이 유효하지 않을 경우
		return ; //함수 중단
	while (pStack->currentElementCount) //원소의 개수가 0이 될 때까지
		free(popLS(pStack)); //스택의 원소들을 전부 Pop하고, 반환받은 노드를 전부 메모리 해제
	free(pStack); //노드들의 메모리가 해제된 후, 스택 메모리 해제
}

int isLinkedStackFull(LinkedStack* pStack) //스택이 꽉 찼는지 여부 체크
{
	if (!pStack) //스택이 유효하지 않을 경우
		return (-1); //오류값 (-1) 반환
	if (pStack->currentElementCount == pStack->maxElementCount) //현재 원소 개수와 최대 원소 개수가 같으면
		return (1); //1 (참) 반환
	return (0); //아니면 0 (거짓) 반환
}

int isLinkedStackEmpty(LinkedStack* pStack) //스택이 비었는지 여부 체크
{
	if (!pStack) //스택이 유효하지 않을 경우
		return (-1); //오류값 (-1) 반환
	if (!pStack->currentElementCount) //현재 원소 개수가 0일 경우
		return (1); //1 (참) 반환
	return (0); //아니면 0 (거짓) 반환
}
