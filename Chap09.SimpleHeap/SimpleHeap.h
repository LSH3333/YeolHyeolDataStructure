/*
 * 힙 구조 구현
 */

#ifndef CHAP09_SIMPLEHEAP_SIMPLEHEAP_H
#define CHAP09_SIMPLEHEAP_SIMPLEHEAP_H

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int Priority; // 우선순위 정수

// node
typedef struct _heapElem
{
    Priority pr; // 값이 작을 수록 우선순위
    HData data;
} HeapElem;

typedef struct _heap
{
    int numOfData;
    HeapElem heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data, Priority pr);
HData HDelete(Heap *ph);

#endif //CHAP09_SIMPLEHEAP_SIMPLEHEAP_H
