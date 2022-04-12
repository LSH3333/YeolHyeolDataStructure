/*
 * 수식 트리 구현
 */
#ifndef CHAP08_EXPTREE_EXPRESSIONTREE_H
#define CHAP08_EXPTREE_EXPRESSIONTREE_H

#include "BinaryTreeTraversal.h"

// 후위 표기법 수식을 받아 expression tree 생성해 루트의 주소값 반환
BTreeNode *MakeExpTree(char *exp);
// 수식 트리 계산
int EvaluateExpTree(BTreeNode *bt);

// pre, in, post fix 기반 표비법 출력
void ShowPrefixTypeExp(BTreeNode *bt);
void ShowInfixTypeExp(BTreeNode *bt);
void ShowPostfixTypeExp(BTreeNode *bt);


#endif //CHAP08_EXPTREE_EXPRESSIONTREE_H
