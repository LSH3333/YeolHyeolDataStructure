/*
 * 이진 탐색 트리 (Binary Search Tree)
 */
#ifndef CHAP11_BINARYSEARCHTREE_BINARYSEARCHTREE_H
#define CHAP11_BINARYSEARCHTREE_BINARYSEARCHTREE_H

#include "BinaryTreeTraversal.h"

typedef BTData BSTData;

// BST 생성 및 초기화
void BSTMakeAndInit(BTreeNode **pRoot);

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode *bst);

// BST를 대상으로 데이터 저장 (노드의 생성과정 포함)
void BSTInsert(BTreeNode **pRoot, BSTData data);

// BST를 대상으로 데이터 탐색
BTreeNode *BSTSearch(BTreeNode *bst, BSTData target);


// 트리에서 노드를 제거하고 제거된 노드의 주소 값을 반환
BTreeNode *BSTRemove(BTreeNode **pRoot, BSTData target);

// 이진 탐색 트리에 저장된 모든 노드의 데이터를 출력
void BSTShowAll(BTreeNode *bst);

#endif //CHAP11_BINARYSEARCHTREE_BINARYSEARCHTREE_H