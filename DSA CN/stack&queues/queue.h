#include <iostream>
using namespace std;
template <typename T>
class Queue
{
    T *data;
    int capacity;
    int size;
    int nextIndex;
    int firstIndex;

public:
    Queue(int s)
    {
        data = new T[s];
        capacity = s;
        size = 0;
        nextIndex = 0;
        firstIndex = -1;
    }

    void enqueue(T data)
    {
        if (size == capacity)
        {
            cout << "Queue is full0";
            return;
        }

        this->data[nextIndex] = data;
        nextIndex = (nextIndex + 1) % capacity;
        size++;
        if (firstIndex = -1)
        {
            firstIndex = 0;
        }
    }

    T dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is empty";
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }

    T front()
    {
        return data[firstIndex];
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }
};
