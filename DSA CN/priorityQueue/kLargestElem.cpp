#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <queue>
vector<int> kSmallest(int input[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
        pq.push(input[i]);

    for (int i = k; i < n; i++)
    {
        if (input[i] > pq.top())
        {
            pq.pop();
            pq.push(input[i]);
        }
    }

    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
int main()
{
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }

    delete[] input;
}