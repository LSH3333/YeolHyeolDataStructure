#include <stdio.h>
#include "DummyDoublyLinkedList.h"

int main()
{
    List list;
    ListInit(&list);

    LInsert(&list, 1);
    LInsert(&list, 2);
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);

    Data data;
    // data 조회
    printf("size of list: %d\n", LCount(&list));
    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);
        printf("\n");
    }

    // 2의 배수 리스트에서 삭제
    if(LFirst(&list, &data))
    {
        if(data % 2 == 0) LRemove(&list);
        while(LNext(&list, &data))
            if(data % 2 == 0) LRemove(&list);
    } printf("\n");

    // data 조회
    printf("size of list: %d\n", LCount(&list));
    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);
        printf("\n");
    }
}
