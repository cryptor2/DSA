#include <iostream>
using namespace std;

#include <unordered_map>

void printIntersection(int input1[], int input2[], int size1, int size2)
{
    unordered_map<int, int> map1;
    for (int i = 0; i < size1; i++)
    {
        if (map1.count(input1[i]) == 0)
            map1[input1[i]] = 1;
        map1[input1[i]]++;
    }

    for (int i = 0; i < size2; i++)
    {
        if (map1.count(input2[i]) != 0 && map1[input2[i]] != 0)
        {
            cout << input2[i] << endl;
            map1[input1[i]]--;
        }
        }
}

int main()
{
    int n;
    cin >> n;

    int *arr1 = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int *arr2 = new int[m];

    for (int i = 0; i < m; ++i)
    {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}