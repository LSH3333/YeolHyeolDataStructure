#include "DLinkedList.h"
#include <stdlib.h>

void ListInit(List *plist)
{
    // dummy node
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}

// header에 없음, 즉 리스트 사용자가 임의로 호출할수 없는 함수
// 정렬기준 없을시 삽입
void FInsert(List *plist, LData data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    // data가 저장된 새로운 노드가 다른 노드 가르키도록함
    newNode->next = plist->head->next;
    // dummy node가 새노드 가르키도록함
    plist->head->next = newNode;
    (plist->numOfData)++;
}

// 정렬기준 있을시 삽입
void SInsert(List *plist, LData data)
{
    // 새 노드 생성
    Node *newNode = (Node*)malloc(sizeof(Node));
    // pred는 더미 노드 가르킴
    Node *pred = plist->head;
    newNode->data = data;

    // pred가 마지막 노드를 가르키지 않고 && comp 함수가 0을 리턴하지 않는다면
    // (새 노드가 들어갈 자리 찾지못했다면) pred를 다음노드로 이동 시킨다
    while(pred->next != NULL && plist->comp(data, pred->next->data) != 0)
    {
        pred = pred->next;
    }

    newNode->next = pred->next; // 새 노드의 오른쪽을 연결
    pred->next = newNode; // 새 노드의 왼쪽을 연결
    (plist->numOfData)++;
}

void LInsert(List *plist, LData data)
{
    // 정렬기준 없다
    if(plist->comp == NULL)
        FInsert(plist, data);
    else
         SInsert(plist, data);
}

int LFirst(List *plist, LData *pdata)
{
    // dummy node가 아무 노드도 가르키고 있지 않다면
    if(plist->head->next == NULL)
        return FALSE;

    // before가 더미노드 가르키도록 하고
    plist->before = plist->head;
    // cur은 첫 노드 가르키도록 함
    plist->cur = plist->head->next;

    // 첫 노드의 데이터 참조
    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, LData *pdata)
{
    if(plist->cur->next == NULL)
        return FALSE;

    // before는 cur를 가르키고
    plist->before = plist->cur;
    // cur은 다음을 가르킴
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

LData LRemove(List *plist)
{
    // 지워야할 노드
    Node *rpos = plist->cur;
    LData rdata = rpos->data;

    // 소멸 대상을 리스트에서 제거
    // before이 cur의 다음 노드를 가르키도록 함으로서 cur 노드가 리스트에서 제외됨
    plist->before->next = plist->cur->next;
    // cur은 before을 가르키도록 함 (한칸 좌측 이동)
    plist->cur = plist->before;

    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int LCount(List *plist)
{
    return plist->numOfData;
}

// 정렬 기준, 두번째 파라미터는 함수 포인터를 전달
void SetSortRule(List *plist, int (*comp)(LData d1, LData d2))
{
    plist->comp = comp;
}
