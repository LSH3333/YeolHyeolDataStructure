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
    int *visitInfo; // 정점 방문 여부 기록
} ALGraph;

// 정점갯수 nv개의 그래프 생성
void GraphInit(ALGraph *pg, int nv);
void GraphDestroy(ALGraph *pg);
void AddEdge(ALGraph *pg, int fromV, int toV);
void ShowGraphInfoEdgeInfo(ALGraph *pg);

// startV 부터 정점 정보 출력 (DFS 기반)
void DFSShowGraphVertex(ALGraph *pg, int startV);

#endif //CHAP14_ALGRAPH_ALGRAPH_H
