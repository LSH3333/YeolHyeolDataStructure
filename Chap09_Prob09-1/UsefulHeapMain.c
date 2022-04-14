#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"

// 우선순위 비교 함수 cmp
int DataPriorityComp(char* str1, char* str2)
{
    return strlen(str2) - strlen(str1);
}

int main()
{

    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);

    HInsert(&pq, "Good morning");
    HInsert(&pq, "I am a boy");
    HInsert(&pq, "Priority Queue");
    HInsert(&pq, "Do you like coffee");
    HInsert(&pq, "I am so happy");

    while(!PQIsEmpty(&pq))
        printf("%s\n", PDequeue(&pq));

}