#include <stdlib.h>
#include <stdio.h>
#include "Deque.h"

void DequeInit(Deque *pdeq)
{
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque *pdeq)
{
    if(pdeq->head == NULL) return TRUE;
    else return FALSE;
}

void DQAddFirst(Deque *pdeq, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    // newNode가 기존 첫 노드 가르키도록함
    newNode->next = pdeq->head;

    // 첫 노드 삽입시, tail이 삽입하는 노드 가리키도록
    if(DQIsEmpty(pdeq))
        pdeq->tail = newNode;
    // 두 번째 이후 노드 삽입시, 기존 첫 노드의 prev가 새 노드 가르키도록
    else
        pdeq->head->prev = newNode;

    newNode->prev = NULL;
    pdeq->head = newNode;
}

void DQAddLast(Deque *pdeq, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = pdeq->tail;

    if(DQIsEmpty(pdeq))
        pdeq->head = newNode;
    else
        pdeq->tail->next = newNode;

    newNode->next = NULL;
    pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque *pdeq)
{
    Node *rnode = pdeq->head;
    Data rdata;
    if(DQIsEmpty(pdeq))
    {
        printf("Deque Memory Error");
        exit(-1);
    }
    rdata = pdeq->head->data;

    // head 한 칸 옮기고 메모리 해제
    pdeq->head = pdeq->head->next;
    free(rnode);

    if(pdeq->head == NULL)
        pdeq->tail = NULL;
    else
        pdeq->head->prev = NULL;

    return rdata;
}

Data DQRemoveLast(Deque *pdeq)
{
    Node *rnode = pdeq->tail;
    Data rdata;
    if(DQIsEmpty(pdeq))
    {
        printf("Deque Memory Error");
        exit(-1);
    }
    rdata = pdeq->tail->data;

    pdeq->tail = pdeq->tail->prev;
    free(rnode);

    // remove 결과 덱이 비었다
    if(pdeq->tail == NULL)
        pdeq->head = NULL;
    else
        pdeq->tail->next = NULL;

    return rdata;
}

Data DQGetFirst(Deque *pdeq)
{
    if(DQIsEmpty(pdeq))
    {
        printf("Deque Memory Error");
        exit(-1);
    }
    return pdeq->head->data;
}

Data DQGetLast(Deque *pdeq)
{
    if(DQIsEmpty(pdeq))
    {
        printf("Deque Memory Error");
        exit(-1);
    }
    return pdeq->tail->data;
}


