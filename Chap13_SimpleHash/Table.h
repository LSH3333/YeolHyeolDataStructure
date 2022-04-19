/*
 * Person을 저장하는 Slot을 갖는 Hash Table
 */

#ifndef CHAP13_SIMPLEHASH_TABLE_H
#define CHAP13_SIMPLEHASH_TABLE_H

#include "Slot.h"

#define MAX_TBL 100

// 사용자 등록 해쉬 함수
typedef int HashFunc(Key k);

typedef struct _table
{
    Slot tbl[MAX_TBL];
    HashFunc * hf; // 해쉬함수
} Table;

void TBLInit(Table *pt, HashFunc *f);
void TBLInsert(Table *pt, Key k, Value v);
// key를 근거로 테이블에서 데이터 삭제
Value TBLDelete(Table *pt, Key k);
// key를 근거로 테이블에서 데이터 탐색
Value TBLSearch(Table *pt, Key k);


#endif //CHAP13_SIMPLEHASH_TABLE_H
