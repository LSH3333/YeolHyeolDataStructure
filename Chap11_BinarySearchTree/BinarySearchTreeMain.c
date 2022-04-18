#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

int main()
{
    BTreeNode *bstRoot;
    BTreeNode *sNode;

    BSTMakeAndInit(&bstRoot);

    BSTInsert(&bstRoot, 5);
    BSTInsert(&bstRoot, 8);
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 4);
    BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 7);

    // 노드 하나씩 제거하면서 노드 중위 순회해서 출력
    BSTShowAll(bstRoot); printf("\n");
    sNode = BSTRemove(&bstRoot, 3);
    free(sNode);

    BSTShowAll(bstRoot); printf("\n");
    sNode = BSTRemove(&bstRoot, 8);
    free(sNode);

    BSTShowAll(bstRoot); printf("\n");
    sNode = BSTRemove(&bstRoot, 1);
    free(sNode);

    BSTShowAll(bstRoot); printf("\n");
    sNode = BSTRemove(&bstRoot, 6);
    free(sNode);

    BSTShowAll(bstRoot); printf("\n");
}