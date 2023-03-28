#include <vector>

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue() {}

    bool isEmpty()
    {
        return pq.size() == 0;
    }
    bool getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (!isEmpty())
            return pq.at(0);
        else
            return 0;
    }

    int getMax()
    {
        if (!isEmpty())
            return pq.at(0);
    }

    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
                break;
            childIndex = parentIndex;
        }
    }

    void insertMax(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int pi = (childIndex - 1) / 2;
            if (pq[childIndex] > pq[pi])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[pi];
                pq[pi] = temp;
            }
            else
                break;
            childIndex = pi;
        }
    }

    int
    removeMax()
    {
        if (isEmpty())
            return 0;
        int ans = pq[0];

        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        // down heapify
        int pi = 0;
        int childL = (2 * pi) + 1;
        int childR = (2 * pi) + 2;
        while (childL < pq.size())
        {
            int maxIndex = pi;
            if (pq[maxIndex] < pq[childL])
            {
                maxIndex = childL;
            }
            if (pq[maxIndex] < pq[childR])
            {
                maxIndex = childR;
            }
            if (maxIndex == pi)
                break;

            int temp = pq[maxIndex];
            pq[maxIndex] = pq[pi];
            pq[pi] = temp;

            pi = maxIndex;
            childL = (2 * pi) + 1;
            childR = (2 * pi) + 2;
        }
        return ans;
    }

    int removeMin()
    {
        if (isEmpty())
            return 0;
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        // down heapify
        int pi = 0;

        int childIndexL = 2 * (pi) + 1;
        int childIndexR = 2 * (pi) + 2;

        while (childIndexL < pq.size())
        {
            int minIndex = pi;
            if (pq[childIndexL] < pq[minIndex])
            {
                minIndex = childIndexL;
            }
            if ((childIndexR < pq.size()) && (pq[childIndexR] < pq[minIndex]))
            {
                minIndex = childIndexR;
            }

            if (minIndex == pi)
            {
                break;
            }

            int temp = pq[minIndex];
            pq[minIndex] = pq[pi];
            pq[pi] = pq[minIndex];

            pi = minIndex;
            childIndexL = 2 * (pi) + 1;
            childIndexR = 2 * (pi) + 2;
        }
        return ans;
    }
};