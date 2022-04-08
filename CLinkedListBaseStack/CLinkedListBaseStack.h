/*
 * 원형 연결 리스트 기반 스택
 */

#ifndef CLINKEDLISTBASESTACK_CLINKEDLISTBASESTACK_H
#define CLINKEDLISTBASESTACK_CLINKEDLISTBASESTACK_H

#include "CLinkedList.h"

typedef struct _cListStack
{
    // 원형 연결 리스트 기반
    List *plist;
} CListStack;

typedef CListStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);


#endif //CLINKEDLISTBASESTACK_CLINKEDLISTBASESTACK_H
