#include <stdio.h>
#include <stdlib.h>
#include "NameCard.h"
#include "ArrayList.h"

int main()
{
    List list;
    NameCard *cpos;
    ListInit(&list);

    // 1. 3명의 전화번호 정보 저장
    cpos = MakeNameCard("LEE", "111-111");
    LInsert(&list, cpos);
    cpos = MakeNameCard("PARK", "222-222");
    LInsert(&list, cpos);
    cpos = MakeNameCard("KIM", "333-333");
    LInsert(&list, cpos);

    // 2. 특정 이름 대상 탐색, 정보 출력
    if(LFirst(&list, &cpos))
    {

    } printf("\n");

    // 3. 특정 이름 대상 탐색 진행, 그 사람 전화번호 정보 변경
}