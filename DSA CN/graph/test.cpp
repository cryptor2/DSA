#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pow2(long long N)
{
    int ans = 0;
    for (int i = 0; i < 64; i++)
    {
        long long x = 1;
        if ((N & (x << i)) > 0)
            ans++;
    }
    return ans;
}


bool compare(const vector<int> &l1, const vector<int> &l2)
{
    return l1[0] < l2[0];
}


int minimumChunckesRequired(long total, vector<vector<int>> list){
    sort(list.begin(), list.end(), compare);
    int n = list.size();
    int m = list[0].size();
    int lastChunkNum = 1;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int start = list[i][0];
        int end = list[i][m - 1];
        ans += pow2(start - lastChunkNum);
        lastChunkNum = end + 1;
    }

    if (list[n - 1][m - 1] != total)
    {
        ans += pow2(total - list[n - 1][m - 1]);
    }

    return ans;
}
int main()
{
    int total, n, m;
    cin >> total >> n >> m;


    vector<vector<int>> list(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> list[i][j];
        }
    }
    cout << minimumChunckesRequired(total, list);

    return 0;
}
