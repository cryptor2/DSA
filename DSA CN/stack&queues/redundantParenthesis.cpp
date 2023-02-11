#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool redundantParenthesis(string s)
{
    int count = 0;
    stack<char> stk;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            stk.push(s[i]);
        }
        else if (s[i] != ')' && stk.size() != 0)
        {
            count++;
        }
        else if (s[i] == ')')
        {
            if (count <= 1)
            {
                return true;
            }
            else if (count > 1)
            {
                stk.pop();
                count = 0;
            }
        }
    }
    return false;
}
int main()
{
    string s = "(x+y*(a-b))";
    // cin >> s;
    cout << redundantParenthesis(s);
}