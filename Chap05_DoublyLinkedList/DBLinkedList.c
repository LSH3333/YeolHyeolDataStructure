#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List *plist)
{
    plist->head = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    // 새로운 노드는 헤드를 가르키도록
    newNode->next = plist->head;
    // 삽입하는 노드가 첫 노드가 아니라면
    if(plist->head != NULL)
        // 헤드가 가르키는 노드의 prev가 새 노드를 가르키도록
        plist->head->prev = newNode;
    // 새로 삽입하는 노드의 prev은 NULL을 가르키도록
    newNode->prev = NULL;
    // head는 새롭게 삽입된 노드를 가르키도록
    plist->head = newNode;
}

int LFirst(List *plist, Data *pdata)
{
    if(plist->head == NULL)
        return FALSE;

    // cur이 head를 가르키도록
    plist->cur = plist->head;
    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, Data *pdata)
{
    if(plist->cur->next == NULL)
        return FALSE;
    // cur 한칸 이동
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}

int LPrevious(List *plist, Data *pdata)
{
    if(plist->cur->prev == NULL)
        return FALSE;

    // cur 한칸 전으로 이동
    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;

    return TRUE;
}

int LCount(List *plist)
{
    return plist->numOfData;
}