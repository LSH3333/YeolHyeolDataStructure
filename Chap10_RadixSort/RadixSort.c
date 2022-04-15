#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM 10

// maxLen은 가장 긴 데이터의 길이
void RadixSort(int arr[], int num, int maxLen)
{
    Queue buckets[BUCKET_NUM];
    int pos, di, divfac=1, radix;
    for(int i = 0; i < BUCKET_NUM; i++)
        QueueInit(&buckets[i]);

    // 가장 긴 데이터의 길이만큼 반복
    for(pos = 0; pos < maxLen; pos++)
    {
        // 정렬 대상 수 만큼 반복
        for(di=0; di < num; di++)
        {
            // N번쨰 자리의 숫자 추출
            radix = (arr[di] / divfac) % 10;

            // 추출한 숫자를 근거로 버킷에 데이터 저장
            Enqueue(&buckets[radix], arr[di]);
        }

        // 버킷 수만큼 반복

    }
}

