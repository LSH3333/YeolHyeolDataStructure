#include <stdio.h>
#include <stdlib.h>
#include "Table.h"

void TBLInit(Table *pt, HashFunc *f)
{
    for(int i = 0; i < MAX_TBL; i++)
        (pt->tbl[i]).status = EMPTY;

    pt->hf = f; // hash func 등록
}

void TBLInsert(Table *pt, Key k, Value v)
{
    int hv = pt->hf(k); // hash func으로 key 가져옴
    pt->tbl[hv].val = v;
    pt->tbl[hv].key = k;
    pt->tbl[hv].status = INUSE;
}

Value TBLDelete(Table *pt, Key k)
{
    int hv = pt->hf(k);
    if((pt->tbl[hv].status != INUSE))
         return NULL;
    else
    {
        (pt->tbl[hv]).status = DELETED;
        return (pt->tbl[hv]).val;
    }
}

Value TBLSearch(Table *pt, Key k)
{
    int hv = pt->hf(k);

    if((pt->tbl[hv]).status != INUSE)
        return NULL;
    else
        return (pt->tbl[hv]).val; // 대상 값 반환
}

