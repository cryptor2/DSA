
template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class stackUsingLL
{
    Node<T> *head;
    int size;

public:
    stackUsingLL()
    {
        head = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push(T data)
    {
        Node<T> *temp = new Node<T>(data);
        if (isEmpty())
        {
            head = temp;
        }
        else
        {
            temp->next = head->next;
            head->next = temp;
        }
        size++;
    }

    T pop()
    {
        if (isEmpty())
        {
            return -10;
        }

        else
        {
            Node<T> *temp = head;
            T val = temp->data;
            head = head->next;
            delete temp;
            size--;
            return val;
        }
    }

    T top()
    {
        if (isEmpty())
        {
            return 0;
        }

        return head->data;
    }

    int sizeLL()
    {
        return size;
    }
};