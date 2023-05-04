#include <iostream>
using namespace std;

int Staircase(int n, int dp[])
{
    if (n == 0)
        return 1;
    if (n < 0)
    {
        return 0;
    }

    int ans3 = 0;
    int ans2 = 0;
    int ans1 = 0;

    if (dp[n - 3] == -1)
    {
        ans3 += Staircase(n - 3, dp);
        dp[n - 3] = ans3;
    }
    else
    {
        ans3 = dp[n - 3];
    }

    if (dp[n - 2] == -1)
    {
        ans2 += Staircase(n - 2, dp);
        dp[n - 2] = ans2;
    }
    else
    {
        ans2 = dp[n - 2];
    }

    if (dp[n - 1] == -1)
    {
        ans1 += Staircase(n - 1, dp);
        dp[n - 1] = ans1;
    }
    else
    {
        ans1 = dp[n - 1];
    }

    return (ans1 + ans2 + ans3);
}

int main()
{
    int n;
    cin >> n;
    int dp[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = -1;
    }
    cout << Staircase(n, dp);
}