#include <iostream>
#include <vector>
using namespace std;

bool ratInAMaze(int arr[4][4], int i, int j, int n)
{

    if (i < 0 || j < 0 || i >= n || j >= n)
        return false;
    if (arr[i][j] == 1 || arr[i][j] == 2)
        return false;
    if (i == n - 1 && j == n - 1)
        return true;
    arr[i][j] = 2;
    return ratInAMaze(arr, i + 1, j, n) || ratInAMaze(arr, i, j + 1, n) || ratInAMaze(arr, i - 1, j, n) || ratInAMaze(arr, i, j - 1, n);
}

int main()
{
    int maze[4][4] = {{1, 0, 0, 0},
                      {1, 1, 0, 1},
                      {0, 1, 0, 0},
                      {1, 1, 1, 0}};

    cout << ratInAMaze(maze, 0, 0, 4);
}