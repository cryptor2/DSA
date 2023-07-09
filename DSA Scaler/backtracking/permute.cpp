#include <iostream>
#include <string>
#include <vector>
using namespace std;

void permute(string str, string ans, vector<int> visited)
{

    if (str.size() == ans.size())
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            ans = ans + str[i];

            permute(str, ans, visited);

            visited[i] = false;
            ans.pop_back();
        }
    }
}

int main()
{
    string str, ans;
    cin >> str;

    vector<int> visited(str.size(), 0);
    permute(str, ans, visited);
}