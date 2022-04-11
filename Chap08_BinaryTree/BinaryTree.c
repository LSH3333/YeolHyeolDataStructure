#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode * MakeBTreeNode()
{
    BTreeNode *nd = (BTreeNode*)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

BTData GetData(BTreeNode *bt)
{
    return bt->data;
}

void SetData(BTreeNode *bt, BTData data)
{
    bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt)
{
    return bt->left;
}

BTreeNode *GetRightSubTree(BTreeNode *bt)
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
    // main 트리의 left child가 이미 존재한다면 삭제하고 연결
    // 이 경우, 삭제되는 트리가 여러개의 노드로 이뤄져 있다면 메모리 누수가 발생한다
    if(main->left != NULL)
        free(main->left);

    main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
    if(main->right != NULL)
        free(main->right);

    main->right = sub;
}
