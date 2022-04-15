#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

// 최초에 front, rear 모두 NULL을 가르킴
void QueueInit(Queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}

// front의 위치만으로 큐가 비었는지 판단함
int QIsEmpty(Queue *pq)
{
    if(pq->front == NULL) return TRUE;
    else return FALSE;
}

void Enqueue(Queue *pq, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node*));
    newNode->next = NULL;
    newNode->data = data;

    // 첫 번째 노드 삽입 시
    if(QIsEmpty(pq))
    {
        pq->front = newNode;
        pq->rear = newNode;
    }
    //
    else
    {
        // 마지막 노드가 새 노드 가르키도록
        pq->rear->next = newNode;
        // rear가 새 노드 가르키도록
        pq->rear = newNode;
    }
}

Data Dequeue(Queue *pq)
{
    Node *delNode;
    Data retData;

    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error");
        exit(-1);
    }

    delNode = pq->front;
    retData = delNode->data;
    pq->front = pq->front->next;

    free(delNode);
    return retData;
}

Data QPeek(Queue *pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error");
        exit(-1);
    }
    return pq->front->data;
}