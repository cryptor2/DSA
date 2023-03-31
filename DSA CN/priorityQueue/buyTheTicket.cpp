#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int buyTicket(int *arr, int n, int k)
{

    int time = 0;
    queue<int> q;
    priority_queue<int> pq;

    // adding element in the queue;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        q.push(i);
    }

    while (q.front() != k || arr[q.front()] != pq.top())
    {

        if (pq.top() > arr[q.front()])
        {
            q.push(q.front());
            q.pop();
        }
        else if (pq.top() == arr[q.front()])
        {
            pq.pop();
            q.pop();
            time++;
        }
    }
    return time + 1;
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

    cout << buyTicket(arr, n, k);

    delete[] arr;
}