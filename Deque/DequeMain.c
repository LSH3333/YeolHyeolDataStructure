#include <stdio.h>
#include "Deque.h"


int main()
{
    Deque deq;
    DequeInit(&deq);

    // data input
    DQAddFirst(&deq, 3);
    DQAddFirst(&deq, 2);
    DQAddFirst(&deq, 1);

    DQAddLast(&deq, 4);
    DQAddLast(&deq, 5);
    DQAddLast(&deq, 6);

    // data dequeue
    while(!DQIsEmpty(&deq))
        printf("%d ", DQRemoveFirst(&deq));

    printf("\n");

    // data input
    DQAddFirst(&deq, 3);
    DQAddFirst(&deq, 2);
    DQAddFirst(&deq, 1);

    DQAddLast(&deq, 4);
    DQAddLast(&deq, 5);
    DQAddLast(&deq, 6);

    // data dequeue
    while(!DQIsEmpty(&deq))
        printf("%d ", DQRemoveLast(&deq));
}
