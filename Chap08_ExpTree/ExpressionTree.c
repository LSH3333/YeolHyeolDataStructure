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

        // 피연산자라
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

int EvaluateExpTree(BTreeNode *bt)
{
    int op1, op2;

    // 단말노드라면 피연산자(숫자)를 리턴함
    if(GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
        return GetData(bt);

    op1 = EvaluateExpTree(GetLeftSubTree(bt));
    op2 = EvaluateExpTree(GetRightSubTree(bt));

    switch(GetData(bt))
    {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
    }
    return 0;
}

// 함수 포인터로 전달됨
void ShowNodeData(int data)
{
    if(0 <= data && data <= 9) // 피연산자
        printf("%d ", data);
    else // 연산자
        printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode *bt)
{
    PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode *bt)
{
    if(bt == NULL) return;

    if(bt->left != NULL || bt->right != NULL) printf(" ( ");

    ShowInfixTypeExp(bt->left);
    ShowNodeData(bt->data);
    ShowInfixTypeExp(bt->right);

    if(bt->left != NULL || bt->right != NULL) printf(" ) ");
}

void ShowPostfixTypeExp(BTreeNode *bt)
{
    PostorderTraverse(bt, ShowNodeData);
}

