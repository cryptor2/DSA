#include <iostream>
#include <stack>
#include <string>
using namespace std;

int minimumBracketReversal(string str)
{
    stack<char> stk;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '{')
            stk.push(str[i]);
        else if (!stk.empty() && stk.top() == '{' && str[i] == '}')
        {
            stk.pop();
        }else
            stk.push(str[i]);
    
    }
    
    int size = stk.size();
    if(size%2 != 0){
       return -1;
    }else{
       int count = 0;
       while(!stk.empty()){
       char c1 = stk.top();
       stk.pop();
       char c2 = stk.top();
       stk.pop();
       if(c1 == c2 )
           count++;
        else
           count += 2;
       }
       return count;
    }
        
}

int main()
{
    string str = "}{";
    cout << minimumBracketReversal(str);
}