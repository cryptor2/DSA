#include <iostream>
using namespace std;

int partition(int arr[], int si, int ei)
{
    int pivotVal = arr[si];
    int count = 0;
    for (int i = si + 1; i <= ei; i++)
    {
        if (arr[i] < pivotVal)
            count++;
    }
    count += si;
    arr[si] = arr[count];
    arr[count] = pivotVal;

    int i = si, j = ei;
    while (i < count && j > count)
    {
        if (arr[i] < pivotVal)
            i++;
        else if (arr[j] >= pivotVal)
            j--;
        else
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return count;
}

void quickSort(int arr[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int c = partition(arr, si, ei);
    quickSort(arr, si, c - 1);
    quickSort(arr, c + 1, ei);
}
int main()
{
    int arr[] = {10, 10, 3, 12, 14, 6, 2};
    quickSort(arr, 0, 5);
    for (int i = 0; i <= 5; i++)
    {
        cout << arr[i] << " ";
    }
}