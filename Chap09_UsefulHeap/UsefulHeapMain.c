#include <stdio.h>
#include "UsefulHeap.h"

// 우선순위 비교 함수 cmp
int DataPriorityComp(char ch1, char ch2)
{
    return ch2-ch1;
}

int main()
{
    Heap heap;
    HeapInit(&heap, DataPriorityComp);

    HInsert(&heap, 'A');
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');
    printf("%c \n", HDelete(&heap));

    HInsert(&heap, 'A');
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');
    printf("%c \n", HDelete(&heap));

    while(!HIsEmpty(&heap))
        printf("%c ", HDelete(&heap));

}