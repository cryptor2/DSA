#include <iostream>
#include "dynamicStackTemp.h"
using namespace std;
int main()
{
    StackUsingArray<int> v;
    v.push(10);
    cout << v.top();
}