#include <iostream>
using namespace std;

void isConnected(int **edges, int n, int s, bool *visited)
{
    // cout << s << endl;
    visited[s] = true;
    // cout << s << " s ";
    for (int i = 0; i < n; i++)
    {

        if (s == i)
            continue;
        if (edges[s][i] == 1)
        {
            if (visited[i])
                continue;
            isConnected(edges, n, i, visited);
        }
    }
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

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;

    isConnected(edges, v, 0, visited);

    int i = 0;
    while (i < v)
    {
        // cout << visited[i];
        if (visited[i] == false)
        {
            cout << false;
            return 0;
        }

        i++;
    }

    cout << true;
}