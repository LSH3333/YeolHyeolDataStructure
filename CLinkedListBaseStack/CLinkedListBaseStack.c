#include <stdio.h>
#include <stdlib.h>
#include "CLinkedListBaseStack.h"

// 원형 연결 리스트를 초기화
void StackInit(Stack *pstack)
{
    pstack->plist = (List*)malloc(sizeof(List));
    ListInit(pstack->plist);
}

int SIsEmpty(Stack *pstack)
{
    if(LCount(pstack->plist) == 0) return TRUE;
    else return FALSE;
}

void SPush(Stack *pstack, Data data)
{
    // head에 노드 추가
    LInsertFront(pstack->plist, data);
}

Data SPop(Stack *pstack)
{
    Data data;
    // stack의 pop은 head의 노드가 나와야되므로
    LFirst(pstack->plist, &data);
    LRemove(pstack->plist);
    return data;
}

Data SPeek(Stack *pstack)
{
    Data data;
    LFirst(pstack->plist, &data);
    return data;
}