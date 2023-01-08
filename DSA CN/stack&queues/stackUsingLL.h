class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class stackUsingLL
{
    Node *head;
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

    void push(int data)
    {
        Node *temp = new Node(data);
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

    int pop()
    {
        if (isEmpty())
        {
            return -10;
        }

        else
        {
            Node *temp = head;
            int val = temp->data;
            head = head->next;
            delete temp;
            size--;
            return val;
        }
    }

    int top()
    {
        if (isEmpty())
        {
            return -10;
        }

        return head->data;
    }

    int sizeLL()
    {
        return size;
    }
};