/*
 * 연결 리스트 기반 스택
 */

#ifndef CHAP06_LISTBASESTACK_LISTBASESTACK_H
#define CHAP06_LISTBASESTACK_LISTBASESTACK_H

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node *next; // 연결 리스트 기반
} Node;

typedef struct _listStack
{
    // head는 항상 스택의 톱을 가르킴. 즉 새로 추가된 노드 가르킴
    Node *head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);


#endif //CHAP06_LISTBASESTACK_LISTBASESTACK_H
