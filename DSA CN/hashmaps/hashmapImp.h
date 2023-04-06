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
    void rehash()
    {
        hashNode<T> **oldBucket = bucket;
        hashNode<T> **bucket = new hashNode<T> *[2 * bucketSize];
        for (int i = 0; i < 2 * bucket; i++)
            bucket[i] = NULL;

        int oldBucketCount = bucketSize;
        bucketSize *= 2;
        count = 0;

        for (int i = 0; i < oldBucketCount; i++)
        {
            hashNode<V> *head = oldBucket[i];
            while (head != NULL)
            {
                insert(head->key, head->value);
                head = head->next;
            }
        }

        for (int i = 0; i < oldBucketCount; i++)
            delete oldBucket[i];
        delete[] oldBucket;
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

        double loadFactor = (1.0 * count) / bucketSize;
        if (loadFactor >= 0.7)
            rehash();
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
