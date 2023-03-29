#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n){
    bool ans = true;
    for (int ci = 1; ci < n; ci++)
    {
        int pi = (ci - 1) / 2;
    if(arr[ci] > arr[pi]) {
        ans = false;
        break;
    }
    }
    return ans;
}

    int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}