#include <iostream>
#include <queue>
using namespace std;

// printing the code
void printDFS(int n, int **edges, int startVertix, bool *visited)
{

    cout << startVertix << " ";
    // marking the visited vertex so we can track the traveled elements.

    for (int i = 0; i < n; i++)
    {
        if (i == startVertix) // if
            continue;
        if (edges[startVertix][i] == 1)
        {
            if (visited[i])
                continue;
            printDFS(n, edges, i, visited);
        }
    }
}

void printBFS(int **edges, int n, int sv, bool *visited)
{

    queue<int> pq;
    pq.push(sv);
    visited[sv] = true;
    while (!pq.empty())
    {
        int curr = pq.front();
        cout << curr << endl;
        pq.pop();
        for (int i = 0; i < n; i++)
        {
            if (i == curr)
                continue;
            if (edges[curr][i] == 1 && visited[i] == false)
            {
                pq.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)

            printBFS(edges, n, i, visited);
    }
}

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)

            printDFS(n, edges, i, visited);
    }
}

int main()
{
    int n; // no. of vertices
    int e; // no. edges
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
            edges[j][i] = 0;
        }
    }
    for (int j = 0; j < e; j++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
}