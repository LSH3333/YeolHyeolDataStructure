#include <cstdio>

void HanoiTowerMove(int num, char from, char by, char to)
{
    if(num == 1)
    {
        // 가장 작은 원반
        printf("원반 1을 %c에서 %c로 이동\n", from, to);
        return;
    }

    // 우선 n-1개의 원반을 A에서 B로 이동시킴 (C를 거쳐)
    HanoiTowerMove(num-1, from, to, by);
    // 맨 아래 큰 원반을 A에서 C로 이동
    printf("원반 %d를 %c에서 %c로 이동\n", num, from, to);
    // B에 있는 n-1개를 C로 이동
    HanoiTowerMove(num-1, by, from, to);
}

int main()
{
    HanoiTowerMove(3, 'A', 'B', 'C');
}