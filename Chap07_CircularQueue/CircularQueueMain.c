#include <stdio.h>
#include "CircularQueue.h"

int main()
{
    Queue q;
    QueueInit(&q);

    // data enqueue
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Enqueue(&q, 4);
    Enqueue(&q, 5);

    // data dequeue
    while(!QIsEmpty(&q))
    {
        printf("%d ", Dequeue(&q));
    }
}