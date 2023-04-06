#include <iostream>
#include <string>
using namespace std;
#include <unordered_map>
string uniqueChar(string str)
{
    unordered_map<char, bool> map;
    string s = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (map.count(str[i]) == 0)
        {
            s += str[i];
            map[str[i]] = true;
        }
    }
    map.clear();
    return s;
}

int main()
{
    string str;
    cin >> str;
    cout << uniqueChar(str);
}