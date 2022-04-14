#include <stdio.h>
#include "UsefulHeap.h" // heap header file

// 정렬 기준 cmp 함수
int PriComp(int n1, int n2)
{
    return n2-n1;
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
    Heap heap;
    HeapInit(&heap, pc);

    // 정렬대상 힙에 저장
    for(int i = 0; i < n; i++)
        HInsert(&heap, arr[i]);

    // 힙의 루트 노드를 빼면서 정렬 완성
    for(int i = 0; i < n; i++)
        arr[i] = HDelete(&heap);
}