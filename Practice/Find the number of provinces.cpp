/***************************
 *
 * Day -2 (Medium)
 *
 * https://www.codingninjas.com/studio/problems/find-the-number-of-states_1377943?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
 *
 * Find the Number of Provinces
 *
 *
 */

void bfs(int node, vector<vector<int>> &roads, vector<int> &vis)
{
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int src = q.front();
        vis[src] = true;
        q.pop();

        for (int dest = 0; dest < vis.size(); dest++)
        {
            if (roads[src][dest] == 1 && vis[dest] != 1)
            {
                q.push(dest);
            }
        }
    }
}

int findNumOfProvinces(vector<vector<int>> &roads, int n)
{
    // Write your code here.
    vector<int> vis(n, 0);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] != 1)
        {
            ans++;
            bfs(i, roads, vis);
        }
    }
    return ans;
}