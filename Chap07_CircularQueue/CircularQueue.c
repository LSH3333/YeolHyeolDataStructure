#include "CircularQueue.h"
#include <stdlib.h>
#include <stdio.h>

// 최초에 큐 텅빈 경우 front와 rear는 동일한 위치 가르킴
void QueueInit(Queue *pq)
{
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue *pq)
{
    // front, rear 동일한 위치 가르킨다면 큐가 비어있음
    if(pq->front == pq->rear) return TRUE;
    else return FALSE;
}

int NextPosIdx(int pos)
{
    // 원형으로 돌기위함
    if(pos == QUE_LEN-1) return 0;
    else return pos+1;
}

void Enqueue(Queue *pq, Data data)
{
    // 큐의 꼬리가 큐의 머리에 한 칸 앞서있다 = 큐가 꽉찼다
    if(NextPosIdx(pq->rear) == pq->front)
    {
        printf("Queue is full");
        exit(-1);
    }

    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue *pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue is full");
        exit(-1);
    }

    pq->front = NextPosIdx(pq->front);
    return pq->queArr[pq->front];
}

Data QPeek(Queue *pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue is full");
        exit(-1);
    }

    // F는 항상 빈 공간 가르키고 있다. peek을 위해서는 다음칸의 데이터를 리턴해줘야함
    return pq->queArr[NextPosIdx(pq->front)];
}
