#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "ArrayBaseStack.h"
#include "ALGraphKruskal.h"

int WhoIsPrecede(int data1, int data2);
// Priority Queue Cmp func
int PQWeightComp(Edge d1, Edge d2)
{
    return d1.weight - d2.weight;
}

void GraphInit(ALGraph *pg, int nv)
{
    // 정점 갯수 nv개
    pg->adjList = (List*)malloc(sizeof(List) * nv);
    pg->numV = nv;
    pg->numE = 0;

    for(int i = 0; i < nv; i++)
    {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
    }

    pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);
    memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
    PQueueInit(&(pg->pqueue), PQWeightComp);
}

void GraphDestroy(ALGraph *pg)
{
    if(pg->adjList != NULL)
        free(pg->adjList);

    if(pg->visitInfo != NULL)
        free(pg->visitInfo);
}

void AddEdge(ALGraph *pg, int fromV, int toV, int weight)
{
    Edge edge = {fromV, toV, weight};

    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    pg->numE += 1;

    // 간선 가중치 정보 우선순위 큐에 저장
    PEnqueue(&(pg->pqueue), edge);
}

void ShowGraphEdgeInfo(ALGraph *pg)
{
    int i;
    int vx;

    for(i = 0; i < pg->numV; i++)
    {
        printf("Vertex connected with %c: ", i+65);

        if(LFirst(&(pg->adjList[i]), &vx))
        {
            printf("%c ", vx+65);
            while(LNext(&(pg->adjList[i]), &vx))
                printf("%c ", vx+65);
        } printf("\n");
    }
}

int WhoIsPrecede(int data1, int data2)
{
    if(data1 < data2)
        return 0;
    else
        return 1;
}

int VisitVertex(ALGraph *pg, int visitV)
{
    if(pg->visitInfo[visitV] == 0) // visitsV 정점에 아직 방문하지 않았다면
    {
        pg->visitInfo[visitV] = 1; // 방문 체크
//        printf("%c ", visitV+65);
        return TRUE;
    }
    return FALSE;
}

void DFSShowGraphVertex(ALGraph *pg, int startV)
{
    Stack stack;
    int visitV = startV;
    int nextV;

    StackInit(&stack);
    VisitVertex(pg, visitV); // 시작 정점 방문
    SPush(&stack, visitV); // 시작 정점 스택에 푸쉬

    while(LFirst(&(pg->adjList[visitV]), &nextV))
    {
        int visitFlag = FALSE;

        // 현재 정점에서 방문할수 있는 다음 정점 찾음
        if(VisitVertex(pg, nextV)) // 방문 성공
        {
            SPush(&stack, visitV);
            visitV = nextV;
            visitFlag = TRUE;
        }
        else
        {
            while(LNext(&(pg->adjList[visitV]), &nextV))
            {
                if(VisitVertex(pg, nextV)) // 방문 성공
                {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }

        // 방문 정점 없음
        if(visitFlag == FALSE)
        {
            if(SIsEmpty(&stack)) break;
            else visitV = SPop(&stack);
        }
    }
    // 이후 탐색을 위해 방문기록 초기화
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void RemoveWayEdge(ALGraph *pg, int fromV, int toV)
{
    int edge;

    // adjList[fromV]에서 정점 toV 찾아서 제거
    if(LFirst(&(pg->adjList[fromV]), &edge))
    {
        if(edge == toV)
        {
            LRemove(&(pg->adjList[fromV]));
            return;
        }

        while(LNext(&(pg->adjList[fromV]), &edge))
        {
            if(edge == toV)
            {
                LRemove(&(pg->adjList[fromV]));
                return;
            }
        }
    }
}

// 그래프에서 간선 삭제
void RemoveEdge(ALGraph *pg, int fromV, int toV)
{
    // 무방향 그래프이기 때문에 두개의 정보 지워야함
    RemoveWayEdge(pg, fromV, toV);
    RemoveWayEdge(pg, toV, fromV);
    (pg->numE)--;
}

// 간선 정보 회복
void RecoverEdge(ALGraph *pg, int fromV, int toV, int weight)
{
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    (pg->numE)++;
}


// 두 정점이 연결되어 있는 상태인지 확인
int IsConnVertex(ALGraph *pg, int v1, int v2)
{
    Stack stack;
    int visitV = v1;
    int nextV;

    StackInit(&stack);
    VisitVertex(pg, visitV);
    SPush(&stack, visitV);



    while(LFirst(&(pg->adjList[visitV]), &nextV))
    {
        int visitFlag = FALSE;

        // DFS 방식으로 정점 탐색하다가 v2 정점에 도착한다면, v1과 v2는 연결된 상태
        if(nextV == v2)
        {
            memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
            return TRUE; // v1,v2는 연결된 상태
        }

        if(VisitVertex(pg, nextV))
        {
            SPush(&stack, visitV);
            visitV = nextV;
            visitFlag = TRUE;
        }
        else
        {
            while(LNext(&(pg->adjList[visitV]), &nextV))
            {
                if(nextV == v2)
                {
                    memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
                    return TRUE; // v1,v2는 연결된 상태
                }

                if(VisitVertex(pg, nextV))
                {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }

        if(!visitFlag)
        {
            if(SIsEmpty(&stack)) break;
            else visitV = SPop(&stack);
        }
    }
    // 이후 탐색을 위해 방문기록 초기화
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
    return FALSE;
}

// 크루스칼 알고리즘 기반 MST 구성
void ConKruskalMST(ALGraph *pg)
{
    Edge recvEdge[20]; // 복원할 간선 정보 저장
    Edge edge;
    int eidx = 0;
    int i;

    // MST의 간선의수 + 1 = 정점의수 이므로
    while(pg->numE+1 > pg->numV)
    {
        // 가중치 가장 큰 간선부터 제거
        edge = PDequeue(&(pg->pqueue));
        RemoveEdge(pg, edge.v1, edge.v2);

        // 간선 제거한 이후에 두 정점을 연결하는 간선이 없다면
        if(!IsConnVertex(pg, edge.v1, edge.v2))
        {
            // 제거한 간선 복원
            RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
            // 큐에서 다시 뺴지않도록 따로 보관
            recvEdge[eidx++] = edge;
        }
    }

    // PQ에서 삭제된 간선 정보 회복
    for(i = 0; i < eidx; i++)
        PEnqueue(&(pg->pqueue), recvEdge[i]);
}

void ShowGraphEdgeWeightInfo(ALGraph *pg)
{
    PQueue copyPQ = pg->pqueue;
    Edge edge;

    while(!PQIsEmpty(&copyPQ))
    {
        edge = PDequeue(&copyPQ);
        printf("(%c-%c), w:%d \n", edge.v1+65, edge.v2+65, edge.weight);
    }
}



