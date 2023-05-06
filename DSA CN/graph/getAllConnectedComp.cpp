#include <iostream>
#include <vector>
using namespace std;

void getAllComponentHelper(int **edges, int v, int start, bool *visited, vector<int> &arr)
{
    visited[start] = true;

    for (int i = 0; i < v; i++)
    {
        if (i == start)
            continue;
        if (edges[start][i] == 1 && !visited[i])
        {
            arr.push_back(i);
            getAllComponentHelper(edges, v, i, visited, arr);
        }
    }
}

void getAllComponent(int **edges, int v, vector<vector<int>> &res)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < v; i++)
    {
        if (visited[i])
            continue;
        vector<int> arr;
        arr.push_back(i);
        getAllComponentHelper(edges, v, i, visited, arr);
        res.push_back(arr);
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
        int s, e;
        cin >> s >> e;
        edges[s][e] = 1;
        edges[e][s] = 1;
    }

    vector<vector<int>> res;
    getAllComponent(edges, v, res);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}