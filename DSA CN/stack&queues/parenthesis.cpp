#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkBalanced(string str)
{
    int i = 0;
    stack<char> c;
    while (str[i] != '\0')
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            c.push(str[i]);
        }

        if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (str[i] == ')' && c.top() == '(')
            {
                c.pop();
            }
            else if (str[i] == '}' && c.top() == '{')
            {
                c.pop();
            }
            else if (str[i] == ']' && c.top() == '[')
            {
                c.pop();
            }
            else
                return false;
        }
        i++;
    }
    return c.empty();
}

int main()
{
    string s = "a+([c+d]+e+d";
    cout << checkBalanced(s);
}