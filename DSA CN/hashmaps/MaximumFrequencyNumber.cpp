#include <iostream>
using namespace std;
#include <unordered_map>
int highestFrequency(int *input, int n)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        if (map.count(input[i]) != 0)
            map[input[i]]++;
        map[input[i]] = 0;
    }

    int key = input[0];
    int value = map[key];

    for (int i = 1; i < n; i++)
    {
        if (map[input[i]] > value)
        {
            key = input[i];
            value = map[key];
        }
    }
    return key;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}