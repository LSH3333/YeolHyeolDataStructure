/*
 * 연결 리스트 기반의 이진 트리 구현
 */

#ifndef CHAP08_BINARYTREE_BINARYTREE_H
#define CHAP08_BINARYTREE_BINARYTREE_H

typedef int BTData;

typedef struct _bTreeNode
{
    BTData data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;
} BTreeNode;

BTreeNode *MakeBTreeNode();
BTData GetData(BTreeNode *bt);
void SetData(BTreeNode *bt, BTData data);

BTreeNode *GetLeftSubTree(BTreeNode *bt);
BTreeNode *GetRightSubTree(BTreeNode *bt);

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);


#endif //CHAP08_BINARYTREE_BINARYTREE_H
