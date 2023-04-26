#include <iostream>
#include <climits>
using namespace std;

int reduceTo1(int n, int dp[])
{
    int ans1 = INT_MAX;
    int ans2 = INT_MAX;
    int ans3 = INT_MAX;

    if (n == 1)
        return 0;
    if (n % 2 == 0)
    {
        if (dp[n / 2] == -1)
        {
            ans2 = reduceTo1(n / 2, dp);
            dp[n / 2] = ans2;
        }
        else
        {
            ans2 = dp[n / 2];
        }
    }
    if (n % 3 == 0)
    {
        if (dp[n / 3] == -1)
        {
            ans3 = reduceTo1(n / 3, dp);
            dp[n / 3] = ans3;
        }
        else
            ans3 = dp[n / 3];
    }

    ans1 = reduceTo1(n - 1, dp);
    dp[n - 1] = ans1;

    return min(ans1, min(ans2, ans3)) + 1;
}
int main()
{
    int n = 0;
    cin >> n;

    int *dp = new int[n];
    for (int i = 0; i < n; i++)
        dp[i] = -1;
    cout << reduceTo1(n, dp);
}