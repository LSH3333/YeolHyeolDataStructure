#include "ListBaseStack.h"
#include <stdio.h>
#include <stdlib.h>

void StackInit(Stack *pstack)
{
    pstack->head = NULL;
}

int SIsEmpty(Stack *pstack)
{
    if(pstack->head == NULL) return TRUE;
    return FALSE;
}

void SPush(Stack *pstack, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    // 새로운 노드는 head가 가르키고 있던 노드를 가르키도록 한다
    newNode->next = pstack->head;

    // head는 항상 새로 삽입된 노드를 가르켜야 한다
    pstack->head = newNode;
}

Data SPop(Stack *pstack)
{
    Data rdata;
    Node *rnode;

    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error");
        exit(-1);
    }
    // 가장 위에 있는 데이터를 지움
    rdata = pstack->head->data;
    rnode = pstack->head;

    pstack->head = pstack->head->next;
    free(rnode);

    return rdata;
}

Data SPeek(Stack *pstack)
{
    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error");
        exit(-1);
    }
    return pstack->head->data;
}