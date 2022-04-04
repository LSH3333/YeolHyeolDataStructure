//#include <stdio.h>
//#include "ArrayList.h"
//
//int main()
//{
//    // 리스트 생성, 초기화
//    List list;
//    ListInit(&list);
//
//    // 정수 1부터 9까지 저장
//    for(int i = 1; i <= 9; i++)
//    {
//        LInsert(&list, i);
//    }
//
//    // 리스트에 저장된 값을 순차적으로 참조하여 그 합을 계산, 출력
//    int sum = 0; int data;
//    if(LFirst(&list, &data))
//    {
//        sum += data; // 첫 요소 더함
//        // 더이상 탐색 요소없다면 LNext는 false를 반환할것임
//        while(LNext(&list, &data))
//        {
//            sum += data;
//        }
//    }
//    printf("sum = %d\n", sum);
//
//    // 리스트에 저장된 값들 중 2의 배수와 3의 배수에 해당하는 값 삭제
//    if(LFirst(&list, &data))
//    {
//        if(data % 2 == 0 || data % 3 == 0)
//            LRemove(&list);
//        while(LNext(&list, &data))
//        {
//            if(data % 2 == 0 || data % 3 == 0)
//                LRemove(&list);
//        }
//    }
//
//    // 리스트에 저장된 데이터를 순서대로 출력
//    if(LFirst(&list, &data))
//    {
//        printf("%d ", data);
//        while(LNext(&list, &data)) printf("%d ", data);
//    }
//}