#include <stdlib.h>
#include <stdio.h>
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode **pRoot)
{
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode *bst)
{
    return GetData(bst);
}

void BSTInsert(BTreeNode **pRoot, BSTData data)
{
    BTreeNode *pNode = NULL; // parent node
    BTreeNode *cNode = *pRoot; // current node, root부터 시작
    BTreeNode *nNode = NULL; // new node

    // new Node가 추가될 위치 찾는다
    while(cNode != NULL)
    {
        // key의 중복 허가하지 않음
        if(data == GetData(cNode)) return;

        // parent의 위치 정보 기억
        pNode = cNode;

        if(GetData(cNode) > data)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    // pNode의 자식 노드로 추가할 새 노드의 생성
    nNode = MakeBTreeNode();
    SetData(nNode, data);

    // pNode의 자식노드로서 삽입
    if(pNode != NULL) // 새 노드가 루트 노드 아니라면
    {
        if(data < GetData(pNode))
            MakeLeftSubTree(pNode, nNode);
        else
            MakeRightSubTree(pNode, nNode);
    }
    else  // new node 가 루트 노드라면
        *pRoot = nNode;
}

BTreeNode *BSTSearch(BTreeNode *bst, BSTData target)
{
    BTreeNode *cNode = bst; // cur node
    BSTData cd; // cur data

    while(cNode != NULL)
    {
        cd = GetData(cNode);

        // 해당하는 노드 찾음
        if(target == cd) return cNode;
        else if(target < cd)
            cNode = GetLeftSubTree(cNode);
        else cNode = GetRightSubTree(cNode);
    }
    return NULL; // 찾는 데이터가 트리에 없음
}

BTreeNode *BSTRemove(BTreeNode **pRoot, BSTData target)
{
    BTreeNode *pVRoot = MakeBTreeNode(); // 가상 루트 노드
    BTreeNode *pNode = pVRoot; // parent node
    BTreeNode *cNode = *pRoot; // current node
    BTreeNode *dNode; // delete node

    // root node를 pVRoot가 가르키는 노드의 오른쪽 자식 노드가 되게 함
    // 이렇게 가상 노드 pVRoot가 루트 노드의 부모가 되게 하는 이유는 삭제 과정 중
    // 삭제 되는 노드의 부모 노드와 자식 노드를 연결하는 과정이 있고, 이 과정 때문에
    // cNode의 부모 노드의 위치를 항상 알고 있어야한다.
    // 그런데 루트 노드는 부모 노드가 없기 떄문에 가상의 부모 노드를 만드는 것.
    ChangeRightSubTree(pVRoot, *pRoot);

    // 삭제 대상인 노드 탐색
    while(cNode != NULL && GetData(cNode) != target)
    {
        pNode = cNode;
        if(target < GetData(cNode))
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }
    if(cNode == NULL) // 삭제 대상이 존재하지 않는다면
        return NULL;

    dNode = cNode; // 삭제 대상을 dNode가 가르키게 한다

    // 1번 경우 : 삭제 대상이 단말 노드인 경우
    if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
    {
        // 삭제 대상 노드 그냥 지우면 됨
        if(GetLeftSubTree(pNode) == dNode)
            RemoveLeftSubTree(pNode);
        else
            RemoveRightSubTree(pNode);
    }
    // 2번 경우 : 삭제 대상이 하나의 자식 노드를 갖는 경우
    else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
    {
        BTreeNode *dcNode; // 삭제 대상의 자식 노드 가르킴

        // dNode가 왼쪽 자식을 갖는지 오른쪽 자식을 갖는지 탐색
        if(GetLeftSubTree(dNode) != NULL)
            dcNode = GetLeftSubTree(dNode);
        else
            dcNode = GetRightSubTree(dNode);

        // 삭제 대상 노드가 부모 노드의 왼쪽 자식이라면 왼쪽으로 연결
        if(GetLeftSubTree(pNode) == dNode)
            ChangeLeftSubTree(pNode, dcNode);
        else
            ChangeRightSubTree(pNode, dcNode);
    }
    // 3번 경우 : 두 개의 자식 노드를 모두 갖는 경우
    else
    {
        BTreeNode *mNode = GetRightSubTree(dNode); // 대체노드 가르킴
        BTreeNode *mpNode = dNode; // 대체 노드의 부모 노드 가르킴
        int delData;

        // 삭제 대상의 대체 노드를 찾는다
        // 삭제되는 노드의 오른쪽 서브 트리의 노드들 중 가장 작은 값 찾아야함
        // 왼쪽으로 계속 가야 가장 작은 값 찾을수 있음
        while(GetLeftSubTree(mNode) != NULL)
        {
            mpNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }
        // 대체 노드에 저장된 값을 삭제할 노드에 대입
        delData = GetData(dNode); // 대입 전 데이터 백업
        SetData(dNode, GetData(mNode)); // 대입

        // 대체 노드의 부모 노드와 자식 노드를 연결
        if(GetLeftSubTree(mpNode) == mNode)
            ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
        else
            ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

        dNode = mNode;
        SetData(dNode, delData); // 백업 데이터 복원
    }

    // 삭제된 노드가 루트 노드인 경우에 대한 추가적인 처리
    if(GetRightSubTree(pVRoot) != *pRoot)
    {
        *pRoot = GetRightSubTree(pVRoot); // root node의 변경을 반영
    }

    free(pVRoot);
    return dNode;
}

void ShowIntData(int data)
{
    printf("%d ", data);
}

// 이진 탐색 트리는 중위 순회할 경우 정렬된 순서로 데이터 참조 가능
void BSTShowAll(BTreeNode *bst)
{
    InorderTraverse(bst, ShowIntData);
}