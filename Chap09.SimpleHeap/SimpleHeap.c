#include "SimpleHeap.h"

void HeapInit(Heap *ph)
{
    ph->numOfData = 0;
}

int HIsEmpty(Heap *ph)
{
    if(ph->numOfData == 0) return TRUE;
    else return FALSE;
}

int GetParentIDX(int idx)
{
    return idx/2;
}

int GetLChildIDX(int idx)
{
    return idx*2;
}

int GetRChildIDX(int idx)
{
    return idx * 2 + 1;
}

// 두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환
int GetHiPriChildIDX(Heap *ph, int idx)
{
    if(GetLChildIDX(idx) > ph->numOfData)
        return 0;
    // LChild가 마지막 노드라면
    else if(GetLChildIDX(idx) == ph->numOfData)
        return GetLChildIDX(idx);
    else
    {
        // 우측 자식이 우선순위가 높다면
        if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
            return GetRChildIDX(idx);
        else
            return GetLChildIDX(idx);
    }
}

void HInsert(Heap *ph, HData data, Priority pr)
{
    int idx = ph->numOfData+1;
    HeapElem nelem = {pr, data};
    
}
