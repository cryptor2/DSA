template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Queue
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {
        Node<T> *temp = new Node<T>(element);
        if (size == 0)
            head = temp;
        else
            tail->next = temp;
        tail = temp;
        size++;
    }
    T front()
    {
        return head->data;
    }

    T dequeue()
    {
        if (head == NULL)
        {
            return 0;
        }
        else
        {
            T ans = head->data;
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            size--;
            return ans;
        }
    }
};