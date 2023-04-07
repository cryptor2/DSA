#include <iostream>
#include <unordered_map>
using namespace std;
int getPairsWithDifferenceK(int *input, int n, int k)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
        map[input[i]]++;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int reqValL = input[i] + k;
        int reqValR = input[i] - k;

        count = count + (map[reqValL] * map[input[i]]) + (map[reqValR] * map[input[i]]);
        map[input[i]] = 0;
    }
    return count;
}
int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}