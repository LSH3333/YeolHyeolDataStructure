/*
 * Deque 기반 Queue 구현 (Deque.h 헤더 사용)
 */

#ifndef CHAP07_DEQUEBASEQUEUE_DEQUEBASEQUEUE_H
#define CHAP07_DEQUEBASEQUEUE_DEQUEBASEQUEUE_H

#include "Deque.h"

typedef Deque Queue;

void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);
void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);
Data QPeek(Queue *pq);


#endif //CHAP07_DEQUEBASEQUEUE_DEQUEBASEQUEUE_H
