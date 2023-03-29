#include <iostream>
#include <vector>
using namespace std;

#include <queue>
int kthLargest(int *arr, int n, int k)
{
    priority_queue<int> pq;
    // adding largest elem

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = 0; i < k - 1; i++)
    {
        pq.pop();
    }
    return pq.top();
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

    int k;
    cin >> k;

    cout << kthLargest(arr, n, k);

    delete[] arr;
}