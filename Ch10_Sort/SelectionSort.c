/*
 * 선택 정렬 (Selection Sort)
 * 시간복잡도 : O(N^2)
 */
#include <stdio.h>

void SelSort(int arr[], int n)
{
    int i, j;
    int maxIdx;
    int temp;

    for(i = 0; i < n-1; i++)
    {
        maxIdx = i; // 기준

        // 최솟값 탐색
        for(j = i+1; j < n; j++)
        {
            if(arr[j] < arr[maxIdx])
                maxIdx = j;
        }

        // swap
        temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;
    }
}

int main()
{
    int arr[4] = {3, 4, 2, 1};

    SelSort(arr, sizeof(arr)/sizeof(int));

    for(int i = 0; i < 4; i++)
        printf("%d ", arr[i]);
}