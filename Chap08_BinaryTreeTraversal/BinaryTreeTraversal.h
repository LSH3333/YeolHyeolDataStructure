/*
 * 이진 트리 순회 함수 포함하는 연결 리스트 기반 이진트리 구현
 */

#ifndef CHAP08_BINARYTREETRAVERSAL_BINARYTREETRAVERSAL_H
#define CHAP08_BINARYTREETRAVERSAL_BINARYTREETRAVERSAL_H

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

// func pointer
typedef void (*VisitFuncPtr)(BTData data);

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action);

#endif //CHAP08_BINARYTREETRAVERSAL_BINARYTREETRAVERSAL_H
