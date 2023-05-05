#include <iostream>
#include <math.h>
#include <climits>
using namespace std;

const int M = 3;
const int N = 4;
int min_cost(int i, int j, int arr[M][N])
{

    if (i >= 3 || j >= 4)
    {
        return 0;
    }
    int ans1 = 0, ans2 = 0, ans3 = 0;
    ans1 += min_cost(i + 1, j, arr);
    ans2 += min_cost(i, j + 1, arr);
    ans3 += min_cost(i + 1, j + 1, arr);
    int res = min(ans3, min(ans1, ans2));

    return res + arr[i][j];
}
int main()
{
    int i = 0;
    int j = 0;
    int arr[][4] = {{3, 4, 1, 2}, {2, 1, 8, 9}, {4, 7, 8, 1}};

    cout << min_cost(i, j, arr);
}