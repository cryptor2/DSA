#include <iostream>
using namespace std;
class ComplexNumber
{
    int real;
    int imaginary;

public:
    ComplexNumber(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    void add(ComplexNumber const &c2)
    {
        this->real = this->real + c2.real;
        this->imaginary = this->imaginary + c2.imaginary;
    }

    void multiply(ComplexNumber const &c2)
    {
        int const TempReal = this->real;
        this->real = (this->real * c2.real) - (this->imaginary * c2.imaginary);
        this->imaginary = (TempReal * c2.imaginary) + (this->imaginary * c2.real);
    }

    void print() const
    {
        cout << real << " + " << imaginary << "i" << endl;
    }
};