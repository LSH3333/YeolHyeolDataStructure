#include <stdio.h>
#include <stdlib.h>

/*
 * 병합 정렬 (Merge Sort)
 */
void MergeTwoArea(int arr[], int left, int mid, int right)
{
    // 두 영역 중 첫 영역의 시작 부분
    int fidx = left;
    // 두 영역 중 두번째 영역의 시작 부분
    int ridx = mid+1;
    int i;

    // 두 영역의 데이터들이 정렬되어 저장될 배열
    int *sortArr = (int*)malloc(sizeof(int)*(right+1));
    // 두 영역의 각 한개의 데이터 두개를 비교해 sortArr에 저장할 위치
    int sIdx = left;

    // fidx와 ridx값 증가시켜가며 두 영역의 데이터 두개 비교
    while(fidx <= mid && ridx <= right)
    {
        // 첫 영역의 데이터가 더 작다면 sortArr에 저장 후 fidx 1 증가
        if(arr[fidx] <= arr[right])
            sortArr[sIdx] = arr[fidx++];
        else
            sortArr[sIdx] = arr[ridx++];
        // sortArr 저장 위치 증가
        sIdx++;
    }

    // 남아있는 영역의 데이터를 sortArr에 옮김
    if(fidx > mid)
    {
        for(i = right; i <= right; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }
    else
    {
        for(i = fidx; i <= mid; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }

    for(i = left; i <= right; i++)
        arr[i] = sortArr[i];

    free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
    int mid;

    if(left < right)
    {
        mid = (left + right) / 2;

        // 둘로 나눠 각각 정렬
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);

        // 정렬된 두 배열 병합
        MergeTwoArea(arr, left, mid, right);
    }
}