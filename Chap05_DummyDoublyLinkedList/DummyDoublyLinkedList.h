/*
 * 헤드와 테일에 더미노드가 있는 양방향 연결 리스트 (Doubly Linked List)
 */

#ifndef CHAP05_DUMMYDOUBLYLINKEDLIST_DUMMYDOUBLYLINKEDLIST_H
#define CHAP05_DUMMYDOUBLYLINKEDLIST_DUMMYDOUBLYLINKEDLIST_H

#define FALSE 0
#define TRUE 1

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node *next;
    struct _node *prev;
} Node;

typedef struct _dbDLinkedList
{
    Node *head;
    Node *tail;
    Node *cur;
    int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, Data data); // 새 노드를 꼬리에 추가함

int LFirst(List *plist, Data *pdata);
int LNext(List *plist, Data *pdata);

Data LRemove(List *plist);
int LCount(List *plist);

#endif //CHAP05_DUMMYDOUBLYLINKEDLIST_DUMMYDOUBLYLINKEDLIST_H
