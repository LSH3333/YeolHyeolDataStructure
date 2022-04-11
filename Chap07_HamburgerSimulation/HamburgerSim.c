/*
 * pg272. Hamburger simulation
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircularQueue.h"

#define CUS_COME_TERM 15 // 고객의 주문 간격

// 버거들 상수
#define CHE_BUR 0
#define BUL_BUR 1
#define DUB_BUR 2

// 제작 시간
#define CHE_TERM 12
#define BUL_TERM 15
#define DUB_TERM 24

int main()
{
    int makeProc = 0; // 햄버거 제작 현황
    int cheOrder = 0, bulOrder = 0, dubOrder = 0;
    int sec;

    Queue que;
    QueueInit(&que);
    srand(time(NULL));

    // for문 1 loop는 1초의 시간이 흐름을 의미함
    for(sec = 0; sec < 3600; sec++)
    {
        // 15초 마다 손님이 온다
        if(sec % CUS_COME_TERM == 0)
        {
            switch(rand() % 3)
            {
                case CHE_BUR:
                    Enqueue(&que, CHE_TERM);
                    cheOrder += 1;
                    break;

                case BUL_BUR:
                    Enqueue(&que, BUL_BUR);
                    bulOrder += 1;
                    break;

                case DUB_BUR:
                    Enqueue(&que, DUB_TERM);
                    dubOrder += 1;
                    break;
            }
        }

        // 햄버거 하나를 다 만들었고 아직 만들어야할 햄버거가 있다면 다음 햄버거 만들기 시작
        if(makeProc <= 0 && !QIsEmpty(&que))
            makeProc = Dequeue(&que);

        makeProc--;
    }

    printf("Simulation Report\n");
    printf(" - Cheese Burger: %d\n", cheOrder);
    printf(" - Bul Burger: %d\n", bulOrder);
    printf(" - Double Burger: %d\n", dubOrder);
    printf(" - Wating room size: %d\n", QUE_LEN);

}

