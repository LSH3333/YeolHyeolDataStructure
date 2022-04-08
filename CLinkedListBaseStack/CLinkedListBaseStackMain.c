#include <stdio.h>
#include "CLinkedListBaseStack.h"

int main()
{
    Stack stack;
    StackInit(&stack);

    // data input
    SPush(&stack, 1);
    SPush(&stack, 2);
    SPush(&stack, 3);
    SPush(&stack, 4);

    // data pop
    while(!SIsEmpty(&stack))
        printf("%d ", SPop(&stack));
}