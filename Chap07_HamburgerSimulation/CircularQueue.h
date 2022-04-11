/*
 * 배열 기반 원형 큐 구현
 */
#ifndef CHAP07_CIRCULARQUEUE_H
#define CHAP07_CIRCULARQUEUE_H

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100
typedef int Data;

typedef struct _cQueue
{
    int front;
    int rear;
    Data queArr[QUE_LEN];
} CQueue; // Circular Queue
typedef CQueue Queue;

void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);

void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);
Data QPeek(Queue *pq);

#endif //CHAP07_CIRCULARQUEUE_H
