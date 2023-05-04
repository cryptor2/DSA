#include <iostream>
using namespace std;

bool DFS(int **edges, int n, int s, int e, bool visited[])
{
    // cout << s << endl;
    visited[s] = true;
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        if (s == e)
        {
            ans = true;

            return ans;
        }
        if (s == n - 1 && i == n - 1 && edges[s][i] != e)
            return false;

        if (s == i)
            continue;
        if (edges[s][i] == 1)
        {
            if (visited[i])
                continue;
            return DFS(edges, n, i, e, visited);
        }
    }
    return ans;
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
    int s, end;
    cin >> s >> end;

    cout << DFS(edges, v, s, end, visited);
}