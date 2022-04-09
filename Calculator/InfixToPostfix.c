#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "InfixToPostfix.h"
#include "ListBaseStack.h"

int GetOpPrec(char op)
{
    switch(op)
    {
        case '*':
        case '/':
            return 5;

        case '+':
        case '-':
            return 3;

        case '(':
            return 1;

        default:
            return -1;
    }
}

// op1의 우선순위가 op2보다 높으면 1, 같다면 0, 작다면 -1 반환
int WhoPrecOp(char op1, char op2)
{
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if(op1Prec > op2Prec) return 1;
    else if(op1Prec < op2Prec) return -1;
    else return 0;
}

// 중위 표기법 -> 후위 표기법 변환 함수
void ConvToRPNExp(char *exp)
{
    Stack stack;
    int expLen = strlen(exp);
    char *convExp = (char*)malloc(sizeof(char) * expLen+1);

    int i, idx = 0;
    char tok, popOp;

    memset(convExp, 0, sizeof(char)*expLen+1);
    StackInit(&stack); // stack 사용

    for(i = 0; i < expLen; i++)
    {
        tok = exp[i];

        // number
        if(isdigit(tok))
        {
            convExp[idx++] = tok;
        }
        else
        {
            switch(tok)
            {
                case '(':
                    SPush(&stack, tok);
                    break;
                case ')':
                    while(1)
                    {
                        popOp = SPop(&stack);
                        if(popOp == '(') break;
                        convExp[idx++] = popOp;
                    }
                    break;

                case '+':
                case '-':
                case '/':
                case '*':
                    // Stack의 top에 있는 연산자의 우선순위가 tok보다 크거나 같을 동안 pop
                    while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
                        convExp[idx++] = SPop(&stack);
                    SPush(&stack, tok);
                    break;
            }
        }
    }

    // stack에 남아있는 모든 연산자들을 convExp 배열로 pop하면서 옮겨담음
    while(!SIsEmpty(&stack))
        convExp[idx++] = SPop(&stack);

    strcpy(exp, convExp);
    free(convExp);
}



