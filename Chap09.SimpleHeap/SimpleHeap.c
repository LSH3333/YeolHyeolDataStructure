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
// idx 노드가 자식이 없으면 0 반환
int GetHiPriChildIDX(Heap *ph, int idx)
{
    // 힙은 완전이진트리이므로 오른쪽 자식 노드만 존재할수 없음
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

    // 트리의 마지막 위치에서부터 위로 올라가면서 비교
    while(idx != 1)
    {
        // 노드의 우선순위와 부모노드 우선순위 비교
        if(pr < (ph->heapArr[GetParentIDX(idx)].pr))
        {
            // 부모와 자리 바꿈
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else
            break;
    }
    // 삽입 노드의 최종 위치
    ph->heapArr[idx] = nelem;
    ph->numOfData += 1;
}

HData HDelete(Heap *ph)
{
    // 삭제될 root node 정보
    HData retData = (ph->heapArr[1]).data;
    // 루트로 이동후 자리 찾아갈 마지막 위치 노드 정보
    HeapElem lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;

    // 현재 노드와 자식들과 비교해 자리 바꿔야한다면 바꿈
    while(childIdx = GetHiPriChildIDX(ph, parentIdx))
    {
        // 자리 찾아가는 노드가 자식들보다 우선순위가 더 높음 = 자리 찾았음
        if(lastElem.pr <= ph->heapArr[childIdx].pr)
            break;
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }

    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return retData;
}
