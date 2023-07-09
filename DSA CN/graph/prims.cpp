#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define V 6
// implementation of prims

int findMinValue(vector<bool> mst, vector<int> key)
{
    int minimum = INT_MAX;
    int vertex;
    for (int i = 0; i < V; i++)
    {
        if (mst[i] == false && key[i] < minimum)
        {
            minimum = key[i];
            vertex = i;
        }
    }
    return vertex;
}

void printMst(int parent[V], int graph[V][V])
{
    for (int i = 0; i < V; i++)
    {
        cout << graph[parent[i]][i] << " ";
    }
}

void findMST(int graph[V][V])
{
    vector<int> key(V, INT_MAX);
    vector<bool> mst(V, false);
    int parent[V];

    parent[0] = -1;
    key[0] = 0;

    for (int i = 0; i < V - 1; i++)
    {

        int minimum = findMinValue(mst, key);

        mst[minimum] = true;

        for (int j = 0; j < V; j++)
        {
            if (graph[minimum][j] != 0 && mst[minimum] == false && graph[minimum][j] < key[j])
            {
                parent[j] = minimum;
                key[j] = graph[minimum][j];
            }
        }
    }
    printMst(parent, graph);
}
int main()
{

    int graph[V][V] = {
        {0, 4, 6, 0, 0, 0},
        {4, 0, 6, 3, 4, 0},
        {6, 6, 0, 1, 8, 0},
        {0, 3, 1, 0, 2, 3},
        {0, 4, 8, 2, 0, 7},
        {0, 0, 0, 3, 7, 0},
    };
    findMST(graph);
    return 0;
}