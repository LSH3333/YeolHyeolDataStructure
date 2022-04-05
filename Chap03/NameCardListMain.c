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
    printf("2. 특정 이름 대상 탐색, 정보 출력\n");
    if(LFirst(&list, &cpos))
    {
        if(NameCompare(cpos, "LEE")==0) ShowNameCardInfo(cpos);
        while(LNext(&list, &cpos))
            if(NameCompare(cpos, "LEE")==0) ShowNameCardInfo(cpos);
    }

    // 3. 특정 이름 대상 탐색 진행, 그 사람 전화번호 정보 변경
    if(LFirst(&list, &cpos))
    {
        if(NameCompare(cpos, "LEE")==0)
            ChangePhoneNum(cpos, "123-123");
        while(LNext(&list, &cpos))
            if(NameCompare(cpos, "LEE")==0)
                ChangePhoneNum(cpos, "123-123");
    }

    // 4. 특정 이름 대상 탐색, 그 사람 정보 삭제
    if(LFirst(&list, &cpos))
    {
        if(NameCompare(cpos, "KIM")==0)
        {
            cpos = LRemove(&list);
            free(cpos);
        }

        while(LNext(&list, &cpos))
        {
            if(NameCompare(cpos, "KIM")==0)
            {
                cpos = LRemove(&list);
                free(cpos);
            }
        }
    }

    // 삭제 후 남은 데이터 전체 출력
    printf("KIM 삭제후\n");
    printf("number of data: %d \n", LCount(&list));
    // 5. 출력
    if(LFirst(&list, &cpos))
    {
        ShowNameCardInfo(cpos);

        while(LNext(&list, &cpos))
            ShowNameCardInfo(cpos);
    }
}