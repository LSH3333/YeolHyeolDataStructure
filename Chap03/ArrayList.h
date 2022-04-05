#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#include "Point.h"
#include "NameCard.h"
#define TRUE	1
#define FALSE	0

#define LIST_LEN	100

// LData에 대한 typedef 선언
// LData의 자료형을 바꿔가면서 사용할수 있도록
typedef NameCard * LData;

typedef struct __ArrayList
{
    LData arr[LIST_LEN]; // 배열 기반의 리스트
    int numOfData; // 리스트에 담긴 데이터의 갯수
    int curPosition; // 참조 위치 기록
} ArrayList;



typedef ArrayList List;

void ListInit(List * plist); // 리스트 초기화
void LInsert(List * plist, LData data); // 데이터 삽입

int LFirst(List * plist, LData * pdata); // 첫 데이터 참조
int LNext(List * plist, LData * pdata); // 두 번째 이후 데이터 참조

LData LRemove(List * plist); // 참조한 데이터 삭제
int LCount(List * plist); // 저장된 데이터 수 반환

#endif