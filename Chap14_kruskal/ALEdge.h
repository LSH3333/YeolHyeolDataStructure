/*
 * 가중치가 포함된 간선의 표현을 위한 구조체 정의
 */

#ifndef CHAP14_KRUSKAL_ALEDGE_H
#define CHAP14_KRUSKAL_ALEDGE_H

typedef struct _edge
{
    int v1; // 간선이 연결하는 첫번째 정점
    int v2; // 두번째 정점
    int weight; // 가중치
} Edge;

#endif //CHAP14_KRUSKAL_ALEDGE_H
