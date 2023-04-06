#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int arr[], int size)
{
    vector<int> ans;
    unordered_map<int, bool> map;
    for (int i = 0; i < size; i++)
    {
        map[arr[i]] = true;
    }

    int start;
    int end;
    int maxLen = 0;
    for (int i = 0; i < size; i++)
    {
        if (map[arr[i]] == true)
        {
            start = arr[i];
            end = arr[i];

            int count = 1;
            // check left
            while (map.count(start - 1) != 0)
            {
                map[start - 1] = false;
                start--;
                count++;
            }
            // check right

            while (map.count(end + 1) != 0)
            {
                map[end + 1] = false;
                end++;
                count++;
            }
            if (maxLen < count)
            {
                maxLen = count;
                if (ans.size() != 0)
                {
                    while (!ans.empty())
                        ans.pop_back();
                }
                ans.push_back(start);
                if (maxLen > 1)
                    ans.push_back(end);
            }
            map[arr[i]] = false;
        }
    }
    return ans;
}

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
