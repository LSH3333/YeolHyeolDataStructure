#include <stdio.h>
#include "ArrayList.h"

void ListInit(List *plist)
{
    plist->numOfData = 0;
    plist->curPosition = -1; // 최초에 아무 위치도 가르키지 않음
}

void LInsert(List *plist, LData data)
{
    if(plist->numOfData >= LIST_LEN)
    {
        puts("저장이 불가능합니다");
        return;
    }
    plist->arr[plist->numOfData] = data;
    plist->numOfData++;
}

int LFirst(List *plist, LData *pdata)
{
    if(plist->numOfData == 0) return FALSE;

    plist->curPosition = 0; // 첫번째 위치의 데이터로 참조 위치 초기화
    *pdata = plist->arr[0];
    return TRUE;
}

int LNext(List *plist, LData *pdata)
{
    // 리스트에 더 이상 참조할 데이터 없음
    if(plist->curPosition >= (plist->numOfData)-1) return FALSE;

    (plist->curPosition)++; // 참조 위치 다음으로 이동
    *pdata = plist->arr[plist->curPosition];
    return TRUE;
}

LData LRemove(List *plist)
{
    // 삭제할 데이터의 인덱스 값 참조
    int rpos = plist->curPosition;
    int num = plist->numOfData;
    int i;
    LData rdata = plist->arr[rpos]; // 삭제할 데이터 임시로 저장

    // 데이터 한칸씩 앞으로 이동
    // rpos 위치의 데이터를 삭제하는게 아닌 뒤의 데이터로 덮어버림
    for(i = rpos; i < num-1; i++)
        plist->arr[i] = plist->arr[i+1];

    (plist->numOfData)--;
    // 참조위치 한칸 되돌림, curPosition은 최근 참조가 이뤄진 데이터의 인덱스 정보 담고있어야함
    (plist->curPosition)--;
    return rdata; // 삭제된 데이터 반환
}

int LCount(List *plist)
{
    return plist->numOfData;
}