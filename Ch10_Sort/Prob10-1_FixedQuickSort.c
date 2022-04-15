
#include <stdio.h>

void _Swap(int arr[], int idx1, int idx2)
{
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int GetPivot(const int arr[], int left, int right)
{
    int tmp[3] = {left, ((left+right)/2), right};

    if(arr[tmp[0]] > arr[tmp[1]])
        _Swap(tmp, 0, 1);

    if(arr[tmp[1]] > arr[tmp[2]])
        _Swap(tmp, 1, 2);

    if(arr[tmp[0]] > arr[tmp[1]])
        _Swap(tmp, 0, 1);

    return tmp[1];
}

int _Partition(int arr[], int left, int right)
{
    // 기준이 되는 pivot
    int pivotIdx = GetPivot(arr, left, right);
    int pivot = arr[pivotIdx];

    int low = left+1;
    int high = right;

    _Swap(arr, left, pivotIdx);

    printf("pivot: %d \n", pivot);

    while(low <= high) // low와 high가 교차되지 않을때까지 반복
    {
        // 피벗보다 큰 값 찾음
        while(pivot >= arr[low] && low <= right) low++;
        // 피벗보다 작은 값 찾음
        while(pivot <= arr[high] && high >= left+1) high--;

        // low, high가 아직 교차되지 않은 상태라면 swap
        if(low <= high)
            _Swap(arr, low, high);
    }
    _Swap(arr, left, high); // 피벗과 high가 가르키는 대상 swap
    return high; // 피벗의 최종 위치 인덱스 반환
}

void _QuickSort(int arr[], int left, int right)
{
    if(left <= right)
    {
        int pivot = _Partition(arr, left, right);
        _QuickSort(arr, left, pivot-1);
        _QuickSort(arr, pivot+1, right);
    }
}

int main()
{
//    int arr[3] = {3,3,3};
//    int arr[7] = {3,2,4,1,7,6,5};
    int arr[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int len = sizeof(arr) / sizeof(int);
    _QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);
    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);
}