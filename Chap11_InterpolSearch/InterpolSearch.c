#include <stdio.h>

int InterpolSearch(int ar[], int first, int last, int target)
{
    if(ar[first] > target || ar[last] < target) return -1;

    int targetIdx = ((double)(target-ar[first]) / (ar[last]-ar[first]) * (last-first)) + first;

    if(ar[targetIdx] == target)
        return targetIdx;
    else if(target < ar[targetIdx])
        return InterpolSearch(ar, first, targetIdx-1, target);
    else
        return InterpolSearch(ar, targetIdx+1, last, target);
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9};
    int idx = InterpolSearch(arr, 0, 4, 2);
    if(idx == -1)
        printf("search failed\n");
    else
        printf("target idx: %d\n", idx);
}