#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount) //배열리스트 스택 생성 및 초기화
{
	ArrayStack	*stack; //반환할 스택 포인터 지정

	if (maxElementCount <= 0) //maxElementCount가 음수이거나 0이면
		return (NULL); //널포인터 반환
	stack = malloc(sizeof(ArrayStack)); //스택에 대한 메모리 할당
	if (!stack) //할당 실패시
		return (NULL); //널포인터 반환
	stack->pElement = malloc(sizeof(StackNode) * maxElementCount); //스택 내부의 원소 배열에 대한 메모리 할당
	if (!stack->pElement) //마찬가지로 할당 실패시
	{
		free(stack); //이전에 할당해주었던 스택 자체의 메모리를 해제
		return (NULL); //널포인터 반환
	}
	stack->maxElementCount = maxElementCount; //스택의 최대 원소 개수를 maxElementCount로 지정
	stack->currentElementCount = 0; //스택의 현재 원소 개수를 0으로 지정
	return (stack); //스택 포인터 반환
}

int	pushAS(ArrayStack* pStack, StackNode element) //스택에 값 Push
{
	int i; //포인터 인덱싱용 i 선언

	if (!pStack) //스택이 존재하지 않을 경우 (널포인터일 경우)
		return (-1); //오류값 (-1) 반환
	i = pStack->currentElementCount; //i는 현재 원소의 개수부터 시작한다
	//배열 리스트 특성상 맨 앞 (top) 에 원소를 추가하기 위해선 뒤의 원소들을 한 칸씩 밀어줘야 하기 때문에
	//뒤에서부터 원소를 이동하기 위해 인덱스를 맨 끝값부터 잡아주는 것
	if (isArrayStackFull(pStack)) //배열이 꽉 찼을 경우
		return (-1); //-1 반환
	while (i > 0) //i를 1씩 감소시켜 가면서 맨 뒤의 원소부터 한 칸씩 뒤로 이동시켜줌
	{ //이를 통해 맨 앞 (top) 에 원소를 추가할 공간을 마련할 수 있다
		(pStack->pElement + i)->data = (pStack->pElement + i - 1)->data;
		i--;
	}
	(pStack->pElement)->data = element.data; //맨 앞 칸에 공간이 생겼다면 해당 공간에 데이터 저장
	pStack->currentElementCount++; //현재 스택의 원소의 개수 1 추가
	return (0); //성공했으므로 0 반환
}

int popAS(ArrayStack* pStack) //스택에서 값 Pop
{
	int i; //포인터 인덱싱용 i 선언
	int elem_return; //반환할 값을 저장해둘 변수 선언

	if (!pStack) //스택이 존재하지 않을 경우 (널포인터일 경우)
		return (0); //오류값 (0) 반환
	i = 0; //i는 0부터 시작하여, 전위연산자를 이용한다
	//1번째 원소부터 한 칸씩 앞으로 당겨줘야 하기 때문에 인덱스를 1부터 시작하기 위함
	elem_return = pStack->pElement->data; //원소를 한 칸씩 앞으로 당기면서 맨 앞의 원소가 덮어씌워지기 때문에,
	//반환해줄 첫 번째 값을 미리 저장한다
	while (++i < pStack->currentElementCount) //i는 currentElementCount 인덱스까지
		*(pStack->pElement + i - 1) = *(pStack->pElement + i); //모든 원소를 한 칸 앞으로 당겨준다
	pStack->currentElementCount--; //원소 개수를 1 감소
	return (elem_return); //아까 저장한 top 원소를 반환
	//배열리스트는 노드가 연속된 값으로 나타나기 때문에 StackNode 대신 data값을 반환하도록 해주었음
}

int peekAS(ArrayStack* pStack) //스택 값 Peek
{
	if (!pStack) //스택이 유효하지 않을 경우
		return (0); //오류값 (0) 반환
	return (pStack->pElement->data); //top 노드의 데이터값 반환
}

void deleteArrayStack(ArrayStack *pStack) //스택 삭제
{
	if (!pStack) //스택이 유효하지 않을 경우
		return ; //함수 중단
	free(pStack->pElement); //스택 내부의 원소 배열 할당 해제
	free(pStack); //스택 메모리 해제
}

int isArrayStackFull(ArrayStack* pStack) //스택이 꽉 찼는지 여부 체크
{
	if (!pStack) //스택이 유효하지 않을 경우
		return (-1); //오류값 (-1) 반환
	if (pStack->currentElementCount == pStack->maxElementCount) //현재 원소 개수와 최대 원소 개수가 같으면
		return (1); //1 (참) 반환
	return (0); //아니면 0 (거짓) 반환
}

int isArrayStackEmpty(ArrayStack* pStack) //스택이 비었는지 여부 체크
{
	if (!pStack) //스택이 유효하지 않을 경우
		return (-1); //오류값 (-1) 반환
	if (!pStack->currentElementCount) //현재 원소 개수가 0일 경우
		return (1); //1 (참) 반환
	return (0); //아니면 0 (거짓) 반환
}
