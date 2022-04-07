#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int OrderForPoint(Point *p1, Point *p2)
{
    if(p1->xpos == p2->xpos)
    {
        if(p1->ypos < p2->ypos) return 0;
        else return 1;
    }
    if(p1->xpos < p2->xpos) return 0;
    else return 1;
}

int main()
{
    List list;
    Point comPos;
    Point *ppos;

    ListInit(&list);
    SetSortRule(&list, OrderForPoint);


    // 4개의 데이터 저장
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);
    LInsert(&list, ppos);

    // 저장된 데이터 출력
    printf("number of data: %d\n", LCount(&list));

    if(LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);

        while(LNext(&list, &ppos))
            ShowPointPos(ppos);
    } printf("\n");

    // xpos가 2인 모든 데이터 삭제
    comPos.xpos = 2;
    comPos.ypos = 0;

    if(LFirst(&list, &ppos))
    {
        if(PointComp(ppos, &comPos) == 1)
        {
            // 삭제한 데이터 리턴, 여기선 Point 구조체 변수의 주소값
            ppos = LRemove(&list);
            free(ppos); // 삭제했으므로 메모리 해제
        }

        while(LNext(&list, &ppos))
        {
            if(PointComp(ppos, &comPos) == 1)
            {
                ppos = LRemove(&list);
                free(ppos);
            }
        }
    }

    // 삭제 후 남은 데이터 전체 출력
    printf("number of data: %d \n", LCount(&list));

    if(LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);

        while(LNext(&list, &ppos)) ShowPointPos(ppos);
    }
    printf("\n");
}