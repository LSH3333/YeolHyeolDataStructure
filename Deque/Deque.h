/*
 * 양방향 연결 리스트 기반 덱 (deque)
 */

#ifndef DEQUE_DEQUE_H
#define DEQUE_DEQUE_H

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node *next;
    struct _node *prev;
} Node;

typedef struct _dlDeque
{
    Node *head;
    Node *tail;
} DLDeque;
typedef DLDeque Deque;

void DequeInit(Deque *pdeq);
int DQIsEmpty(Deque *pdeq);

void DQAddFirst(Deque *pdeq, Data data);
void DQAddLast(Deque *pdeq, Data data);

Data DQRemoveFirst(Deque *pdeq);
Data DQRemoveLast(Deque *pdeq);

Data DQGetFirst(Deque *pdeq);
Data DQGetLast(Deque *pdeq);


#endif //DEQUE_DEQUE_H
