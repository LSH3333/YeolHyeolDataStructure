/*
 * 퀵 정렬
 */
#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
    // 기준이 되는 pivot
    int pivot = arr[left];
    int low = left+1;
    int high = right;

    printf("pivot: %d \n", pivot);

    while(low <= high) // low와 high가 교차되지 않을때까지 반복
    {
        // 피벗보다 큰 값 찾음
        while(pivot >= arr[low] && low <= right) low++;
        // 피벗보다 작은 값 찾음
        while(pivot <= arr[high] && high >= left+1) high--;

        // low, high가 아직 교차되지 않은 상태라면 swap
        if(low <= high)
            Swap(arr, low, high);
    }
    Swap(arr, left, high); // 피벗과 high가 가르키는 대상 swap
    return high; // 피벗의 최종 위치 인덱스 반환
}

void QuickSort(int arr[], int left, int right)
{
    if(left <= right)
    {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot-1);
        QuickSort(arr, pivot+1, right);
    }
}
//
//int main()
//{
//
//    int arr[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
//    int len = sizeof(arr) / sizeof(int);
//    QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);
//    for(int i = 0; i < len; i++)
//        printf("%d ", arr[i]);
//}