/*
 * 배열을 기반으로 구현한 스택
 */
#ifndef CHAP06_ARRAYBASESTACK_ARRAYBASESTACK_H
#define CHAP06_ARRAYBASESTACK_ARRAYBASESTACK_H

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data;

typedef struct _arrayStack
{
    Data stackArr[STACK_LEN]; // 배열 기반 스택
    int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);


#endif //CHAP06_ARRAYBASESTACK_ARRAYBASESTACK_H
