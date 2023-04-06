#include <string>
using namespace std;

template <typename T>
class hashNode
{
public:
    string key;
    T value;
    hashNode *next;

    hashNode(string key, T value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~hashNode()
    {
        delete next;
    }
};

template <typename T>
class ourmap
{
    int bucketSize;
    int count;
    hashNode<T> **bucket;

public:
    ourmap()
    {
        count = 0;
        bucketSize = 5;
        bucket = new hashNode<T> *[bucketSize];
        for (int i = 0; i < bucketSize; i++)
        {
            bucket[i] = NULL;
        }
    }

    ~ourmap()
    {
        for (int i = 0; i < bucketSize; i++)
            delete bucket[i];
        delete[] bucket;
    }

    int size()
    {
        return count;
    }

    T getValue(string key)
    {
        int index = getBucketIndex(key);
        hashNode<T> *head = bucket[index];
        while (head != NULL)
        {
            if (head->key == key)
                return head->value;
            head = head->next;
        }
        return 0;
    }

private:
    int getBucketIndex(string key)
    {
        int hash = 0;
        int coefficient = 1;

        for (int i = key.length() - 1; i >= 0; i--)
        {
            hash += key[i] * coefficient;
            hash %= bucketSize;

            coefficient *= 37;
            coefficient %= bucketSize;
        }

        return hash % bucketSize;
    }

public:
    void insert(string key, T value)
    {
        int index = getBucketIndex(key);
        hashNode<T> *head = bucket[index];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = bucket[index];
        hashNode<T> *newNode = new hashNode<T>(key, value);
        bucket[index] = newNode;
        newNode->next = head;
        count++;
    }

    T remove(string key)
    {
        int index = getBucketIndex(key);
        hashNode<T> *head = bucket[index];
        hashNode<T> *prev = nullptr;

        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == nullptr)
                {
                    bucket[index] = head->next;
                }
                else
                    prev->next = head->next;
                T value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};
