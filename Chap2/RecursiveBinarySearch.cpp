#include <cstdio>

int BinarySearchRecur(int ar[], int first, int last, int target)
{
    if(first > last) return -1; // 실패

    int mid = (first + last) / 2;
    if(ar[mid == target]) return mid;
    else if(target < ar[mid])
        return BinarySearchRecur(ar, first, mid-1, target);
    else
        return BinarySearchRecur(ar, mid+1, last, target);
}

//int main()
//{
//    int arr[] = {1, 3, 5, 7, 9};
//    int idx;
//    idx = BinarySearchRecur(arr, 0, sizeof(arr)/sizeof(int)-1, 7);
//
//}