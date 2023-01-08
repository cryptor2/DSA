#include <iostream>
#include "stackUsingLLtemp.h"
using namespace std;
int main()
{
    stackUsingLL<int> v;
    v.push(10);
    cout << v.top();
}