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

// 순회
void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action);

// 순회하며 메모리 해제
void DeleteTree(BTreeNode *bt);

// 이진 탐색 트리를 위한 함수들
// 왼쪽 자식 노드를 트리에서 제거, 제거된 노드 주소값 반환
BTreeNode *RemoveLeftSubTree(BTreeNode *bt);
BTreeNode *RemoveRightSubTree(BTreeNode *bt);
// 메모리 소멸을 수반하지 않고 main의 왼쪽 자식 노드를 sub 노드로 변경
void ChangeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void ChangeRightSubTree(BTreeNode *main, BTreeNode *sub);

#endif //CHAP08_BINARYTREETRAVERSAL_BINARYTREETRAVERSAL_H
