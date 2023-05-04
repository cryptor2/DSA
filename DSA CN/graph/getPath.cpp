#include <iostream>
#include <vector>
using namespace std;

bool DFS(int **edges, int n, int start, int end, bool visited[], vector<int> &res)
{
    // cout << s << endl;
    visited[start] = true;

    for (int i = 0; i < n; i++)
    {

        if (end == start)
        {
            res.push_back(start);
            return true;
        }
        if (i == start)
            continue;
        // cout << " ddd" << endl;
        if (start == n - 1 && i == n - 1 && edges[start][i] != end)
            return false;
        if (edges[start][i] == 1 && !visited[i])
        {

            bool ans = DFS(edges, n, i, end, visited, res);
            res.push_back(start);
            return ans;
        }
    }
    return false;
}

int main()
{
    int v, e;
    cin >> v >> e;

    int **edges = new int *[v];

    for (int i = 0; i < v; i++)
    {

        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool visited[v] = {false};
    vector<int> res;
    int s, end;
    cin >> s >> end;

    cout << "res " << DFS(edges, v, s, end, visited, res);
    cout << res.size();
    for (int i = 0; i < res.size(); i++)
        cout << " " << res[i] << " ";
}