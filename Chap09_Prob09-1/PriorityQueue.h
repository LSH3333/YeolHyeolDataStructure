/*
 * 힙 구조를 기반으로한 우선순위 큐 구현
 */
#ifndef CHAP09_USEFULHEAP_PRIORITYQUEUE_H
#define CHAP09_USEFULHEAP_PRIORITYQUEUE_H

#include "UsefulHeap.h"

typedef Heap PQueue;
typedef HData PQData;

void PQueueInit(PQueue *ppq, PriorityComp pc);
int PQIsEmpty(PQueue *ppq);

void PEnqueue(PQueue *ppq, PQData data);
PQData PDequeue(PQueue *ppq);

#endif //CHAP09_USEFULHEAP_PRIORITYQUEUE_H
