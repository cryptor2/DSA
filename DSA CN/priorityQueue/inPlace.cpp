#include <iostream>

using namespace std;

void heapSort(int pq[], int n)
{
    // heapify
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int pi = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[pi])
            {
                int temp = pq[pi];
                pq[pi] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else
                break;
            childIndex = pi;
        }
    }

    // remove elem;
    int size = n;
    while (size > 1)
    {

        int temp = pq[size-1];
        pq[size - 1] = pq[0];
        pq[0] = temp;
        size--;

        // down heapify
        int pi = 0;
        int childL = (2 * pi) + 1;
        int childR = (2 * pi) + 2;

        while (childL < size)
        {
            int minIndex = pi;
            if (pq[childL] < pq[minIndex])
                minIndex = childL;
            if (childR < size && pq[childR] < pq[minIndex])
                minIndex = childR;
            if (minIndex == pi)
                break;

            int temp = pq[pi];
            pq[pi] = pq[minIndex];
            pq[minIndex] = temp;

            pi = minIndex;
            childL = (2 * pi) + 1;
            childR = (2 * pi) + 2;
        }
    }
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    heapSort(input, size);

    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}