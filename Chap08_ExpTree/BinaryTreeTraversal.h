
#ifndef CHAP08_EXPTREE_BINARYTREETRAVERSAL_H
#define CHAP08_EXPTREE_BINARYTREETRAVERSAL_H

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

// 순회
void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action);

// 순회하며 메모리 해제
void DeleteTree(BTreeNode *bt);
#endif //CHAP08_EXPTREE_BINARYTREETRAVERSAL_H
