#include <iostream>
#include "classComplexNumber.cpp"
using namespace std;

int main()
{
    ComplexNumber f1(4, 5);
    ComplexNumber f2(1, 2);
    f1.multiply(f2);
    f1.print();
    f2.print();
}