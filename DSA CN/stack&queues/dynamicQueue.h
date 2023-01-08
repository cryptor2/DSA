#include <iostream>
using namespace std;
template <typename T>
class Queue
{
    T *data;
    int capacity = 0;
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
            T *temp = new T[capacity * 2];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++)
            {
                temp[j] = this->data[i];
                j++;
            }
            for (int i = 0; i < firstIndex; i++)
            {
                temp[j] = this->data[i];
                j++;
            }

            delete[] this->data;
            this->data = temp;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
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
