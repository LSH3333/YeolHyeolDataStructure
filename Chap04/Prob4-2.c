//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct _node
//{
//    int data;
//    struct _node *next;
//} Node;
//
//int main()
//{
//    Node *head = NULL;
//    Node *tail = NULL;
//    Node *cur = NULL;
//
//    Node *newNode = NULL;
//    int readData;
//
//    // dummy node
//    Node *dummy = (Node*)malloc(sizeof(Node));
//    head = dummy;
//    tail = dummy; //
//
//    while(1)
//    {
//        printf("enter number: ");
//        scanf("%d", &readData);
//        if(readData < 1) break;
//
//        newNode = (Node*)malloc(sizeof(Node));
//        newNode->data = readData;
//        newNode->next = NULL;
//
//        tail->next = newNode;
//        tail = newNode;
//    }
//    printf("\n");
//
//    // 출력
//    if(tail == head)
//    {
//        printf("empty list\n");
//    }
//    else
//    {
//        cur = head;
//
//        while(cur->next != NULL)
//        {
//            cur = cur->next;
//            printf("%d ", cur->data);
//        }
//    }
//
//    // 메모리 해제
//    if(head == NULL)
//    {
//        return 0;
//    }
//    else
//    {
//        Node *delNode = head;
//        Node *delNextNode = head->next;
//
//        while(delNextNode != NULL)
//        {
//            delNode = delNextNode;
//            delNextNode = delNextNode->next;
//            free(delNode);
//        }
//    }
//}