//#include <stdio.h>
//#include "DLinkedList.h"
//#include "Point.h"
//
//// 오름차순 정렬
//// 정렬기준은 리스트의 사용자가 정할수있도록 메인함수가 있는 소스파일에 있어야함
//int WhoIsPrecede(int d1, int d2)
//{
//    if(d1 < d2) // d1이 정렬순서상 앞선다
//        return 0;
//    else
//        return 1;
//}
//
//
//int main()
//{
//    List list;
//    int data;
//    ListInit(&list);
//    // 정렬 기준 등록
//    SetSortRule(&list, WhoIsPrecede);
//
//    LInsert(&list, 11);  LInsert(&list, 11);
//    LInsert(&list, 22);  LInsert(&list, 22);
//    LInsert(&list, 33);
//
//    printf("number of cur data: %d \n", LCount(&list));
//
//    if(LFirst(&list, &data))
//    {
//        printf("%d ", data);
//
//        while(LNext(&list, &data))
//            printf("%d ", data);
//    }
//    printf("\n\n");
//
//    if(LFirst(&list, &data))
//    {
//        if(data == 22)
//            LRemove(&list);
//
//        while(LNext(&list, &data))
//        {
//            if(data == 22)
//                LRemove(&list);
//        }
//    }
//
//    printf("number of cur data: %d \n", LCount(&list));
//
//    if(LFirst(&list, &data))
//    {
//        printf("%d ", data);
//
//        while(LNext(&list, &data))
//            printf("%d ", data);
//    }
//    printf("\n\n");
//    return 0;
//}