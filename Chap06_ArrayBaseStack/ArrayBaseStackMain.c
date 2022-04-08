#include <stdio.h>
#include "ArrayBaseStack.h"

int main()
{
    Stack stack;
    StackInit(&stack);

    // data push
    SPush(&stack, 1);
    SPush(&stack, 2);
    SPush(&stack, 3);
    SPush(&stack, 4);

    // data pop
    while(!SIsEmpty(&stack))
        printf("%d ", SPop(&stack));
}