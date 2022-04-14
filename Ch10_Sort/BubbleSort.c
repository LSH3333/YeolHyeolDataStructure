/*
 * 버블 정렬 (Bubble Sort)
 * 시간복잡도 : O(N^2)
 */

#include <stdio.h>

void BubbleSort(int arr[], int n)
{
    int i, j;
    int temp;

    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < (n-i)-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                // swap
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//int main()
//{
//    int arr[4] = {3, 2, 4, 1};
//
//    BubbleSort(arr, sizeof(arr)/sizeof(int));
//
//    for(int i = 0; i < 4; i++)
//        printf("%d ", arr[i]);
//}