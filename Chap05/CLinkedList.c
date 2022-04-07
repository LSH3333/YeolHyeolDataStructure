#include "CLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List *plist)
{
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
}

// tail에 노드 추가
void LInsertFront(List *plist, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    // tail이 NULL을 가르키고 있다면 리스트가 empty 상태
    if(plist->tail == NULL)
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // 새 노드가 기존의 첫 노드 가르키도록
        newNode->next = plist->tail->next;
        // tail이 가르키던 노드 즉 마지막 노드가 새 노드 즉 첫 노드 가르키도록
        plist->tail->next = newNode;
    }
    (plist->numOfData)++;
}

// head에 노드 추가
void LInsert(List *plist, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if(plist->tail == NULL)
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode; // LInsertFront와의 유일한 차이점
    }
    (plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
    if(plist->tail == NULL) return FALSE;

    plist->before = plist->tail; // before는 꼬리 가르키도록
    plist->cur = plist->tail->next; // cur은 머리를 가르키도록

    *pdata = plist->cur->data;
    return TRUE;
}

// before, cur이 한 칸씩 다음 노드로 이동
int LNext(List *plist, Data *pdata)
{
    if(plist->tail == NULL) return FALSE;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

Data LRemove(List *plist)
{
    // 삭제할 노드
    Node *rpos = plist->cur;
    Data rdata = rpos->data;

    // 예외 상황 1. 삭제할 노드가 tail이 가르키는 경우
    if(rpos == plist->tail)
    {
        // tail이 head를 가르키는 경우
        // 즉 예외상황 2. 리스트에 홀로 남은 노드를 지우는 경우
        if(plist->tail == plist->tail->next)
            plist->tail = NULL;
        else
            plist->tail = plist->before;
    }
    // before이 삭제할 노드 다음 노드 가르키도록
    plist->before->next = plist->cur->next;
    // cur은 한칸 뒤로
    plist->cur = plist->before;

    free(rpos);
    (plist->numOfData)--;
    return rdata;

}

int LCount(List *plist)
{
    return plist->numOfData;
}

