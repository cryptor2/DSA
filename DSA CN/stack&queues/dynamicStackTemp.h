#include <iostream>
#include <climits>

using namespace std;
template <typename T>
class StackUsingArray
{
    T *data;
    int capacity;
    int nextIndex = 0;

public:
    StackUsingArray()
    {
        data = new T[capacity];
        nextIndex = 0;
    }
    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(int number)
    {
        if (nextIndex == capacity)
        {
            T *newData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity = 2 * capacity;
            delete[] data;
            data = newData;
        }
        data[nextIndex] = number;
        nextIndex++;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty";
            return INT_MIN;
        }
        else
        {
            nextIndex--;
            return data[nextIndex];
        }
    }

    T top()
    {
        return data[nextIndex - 1];
    }
};