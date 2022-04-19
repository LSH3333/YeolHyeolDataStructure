/*
 * 인접 리스트 기반의 무방향 그래프 구현
 */
#ifndef CHAP14_ALGRAPH_ALGRAPH_H
#define CHAP14_ALGRAPH_ALGRAPH_H

#include "DLinkedList.h" // 연결 리스트 사용
// 정점의 이름 상수화
enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _val
{
    int numV;
    int numE;
    List *adjList;
} ALGraph;

// 정점갯수 nv개의 그래프 생성
void GraphInit(ALGraph *pg, int nv);
void GraphDestroy(ALGraph *pg);
void AddEdge(ALGraph *pg, int fromV, int toV);
void ShowGraphInfoEdgeInfo(ALGraph *pg);

#endif //CHAP14_ALGRAPH_ALGRAPH_H
