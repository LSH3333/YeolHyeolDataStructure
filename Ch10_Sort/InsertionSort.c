#include <stdio.h>
/*
 * 삽입 정렬 (Insertion Sort)
 * 시간복잡도 : O(N^2)
 */
void InsertSort(int arr[], int n)
{
    int i, j;
    int insData;

    for(i = 1; i < n; i++)
    {
        insData = arr[i]; // 정렬대상

        for(j = i-1; j >= 0; j--)
        {
            if(arr[j] > insData)
                arr[j+1] = arr[j]; // 비교대상 한 칸 뒤로 밀림
            else
                break;
        }
        // 찾은 위치에 정렬 대상 삽입
        arr[j+1] = insData;
    }
}
//
//int main()
//{
//    int arr[5] = {5,3,2,4,1};
//    InsertSort(arr, sizeof(arr)/sizeof(int));
//    for(int i = 0; i < 5; i++)
//        printf("%d ", arr[i]);
//}