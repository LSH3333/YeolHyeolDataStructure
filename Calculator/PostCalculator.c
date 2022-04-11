#include "ListBaseStack.h"
#include <ctype.h>
#include <string.h>

int EvalRPNExp(char *exp)
{
    Stack stack;
    int expLen = strlen(exp);
    int i;
    char tok, op1, op2;

    StackInit(&stack);

    for(i = 0; i < expLen; i++)
    {
        tok = exp[i];

        if(isdigit(tok))
        {
            SPush(&stack, tok-'0');
        }
        else
        {
            // 스택에서 먼저 꺼낸 연산자가 두번째 피연산자가 되어야한다
            op2 = SPop(&stack);
            op1 = SPop(&stack);

            switch(tok)
            {
                case '+':
                    SPush(&stack, op1+op2);
                    break;
                case '-':
                    SPush(&stack, op1-op2);
                    break;
                case '*':
                    SPush(&stack, op1*op2);
                    break;
                case '/':
                    SPush(&stack, op1/op2);
                    break;
            }
        }
    }
    return SPop(&stack);
}


