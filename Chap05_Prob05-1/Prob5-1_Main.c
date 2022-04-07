#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

Employee* WhoIsShift(List *plist, char name[], int next)
{
    Employee *ret;

    // 인자로 전달받은 name 찾음
    if(LFirst(plist, &ret))
    {
        // 이름 다른 경우
        if(strcmp(ret->name, name) != 0)
        {
            for(int i = 0; i < LCount(plist)-1; i++)
            {
                LNext(plist, &ret);
                // 이름 같으면 탈출
                if(strcmp(ret->name, name) == 0) break;
            }
        }
    }

    // next 번째 인원 찾음
    for(int i = 0; i < next; i++)
    {
        LNext(plist, &ret);
    }

    return ret;
}

int main()
{
    List list;
    ListInit(&list);

    Employee *emp;

    // 4명의 직원 리스트에 추가
    emp = (Employee*)malloc(sizeof(Employee));
    strcpy(emp->name, "LEE");
    emp->employeeNumber = 100;
    LInsert(&list, emp);

    emp = (Employee*)malloc(sizeof(Employee));
    strcpy(emp->name, "PARK");
    emp->employeeNumber = 200;
    LInsert(&list, emp);

    emp = (Employee*)malloc(sizeof(Employee));
    strcpy(emp->name, "KIM");
    emp->employeeNumber = 300;
    LInsert(&list, emp);

    emp = (Employee*)malloc(sizeof(Employee));
    strcpy(emp->name, "YOON");
    emp->employeeNumber = 400;
    LInsert(&list, emp);


    // KIM 3일 후 당직
    emp = WhoIsShift(&list, "KIM", 3);
    printf("%s ", emp->name);
}