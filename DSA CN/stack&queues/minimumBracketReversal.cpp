#include <iostream>
#include <stack>
using namespace std;

int minimumBracketReversal(string str)
{
    stack<char> stk;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '{')
            stk.push(str[i]);
        else if (str[i] == '}')
        {
            if (stk.size() != 0)
        }
    }
}

int main()
{
}