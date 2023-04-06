#include <iostream>
#include "hashmapImp.h"
using namespace std;
int main()
{
    ourmap<int> map;
    map.insert("hi", 1);
    map.insert("hlo", 2);
    cout << map.getValue("hi");
    cout << map.size();
    cout << map.remove("hi");
}