/*********************************************************
 * (06/10/23)
 *
 *                      Day - 2
 *
 *
BFS(Easy)
https://www.codingninjas.com/studio/problems/bfs-in-graph_973002?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
***********************************************************/

vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    // Write your code here.
    vector<int> ans;
    vector<int> vis(n, 0);
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty())
    {
        int src = q.front();
        ans.push_back(src);
        q.pop();

        for (auto dest : adj[src])
        {
            if (vis[dest] != 1)
            {
                // cout << dest<< endl;
                q.push(dest);
                vis[dest] = 1;
            }
        }
    }
    return ans;
}