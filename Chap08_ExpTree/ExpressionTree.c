#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "ExpressionTree.h"

BTreeNode  *MakeExpTree(char *exp)
{
    Stack stack;
    StackInit(&stack);
    BTreeNode *pnode;

    int expLen = strlen(exp);
    int i;

    for(i = 0; i < expLen; i++)
    {
        pnode = MakeBTreeNode();

        // 피연산자라면
        if(isdigit(exp[i]))
        {
            SetData(pnode, exp[i]-'0');
        }
        else // 연산자라면
        {
            // stack에서 pop하 노드를 서브트리로 만듦
            MakeRightSubTree(pnode, SPop(&stack));
            MakeLeftSubTree(pnode, SPop(&stack));
            SetData(pnode, exp[i]);
        }
        SPush(&stack, pnode);
    }
    return SPop(&stack);
}

