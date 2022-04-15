/*
 * 연결 리스트 기반 큐 구현
 */

#ifndef CHAP07_LISTBASEQUEUE_LISTBASEQUEUE_H
#define CHAP07_LISTBASEQUEUE_LISTBASEQUEUE_H

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node *next;
} Node;

typedef struct _lQueue
{
    Node *front;
    Node *rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);

void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);
Data QPeek(Queue *pq);

#endif //CHAP07_LISTBASEQUEUE_LISTBASEQUEUE_H
