#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *takeInput_Better()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int len(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    // cout << "len " << len << endl;
    return count;
}

Node *bubbleSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // cout << "length call " << endl;
    int length = len(head);
    cout << "length  " << length;
    int swap;
    cout << "BubbleSort";
    for (int i = 0; i <= length; i++)
    {
        Node *prev = NULL;
        Node *c = head;
        Node *next = c->next;
        swap = 0;
        while (c->next != NULL)
        {
            if (c->data <= next->data)
            {
                prev = c;
                c = next;
                next = next->next;
            }
            else if (c->data > next->data)
            {
                if (prev == NULL)
                {
                    head = c->next;
                    c->next = head->next;
                    head->next = c;
                    prev = head;
                    next = c->next;
                }
                else
                {
                    c->next = next->next;
                    prev->next = next;
                    next->next = c;
                    prev = prev->next;
                    next = c->next;
                }
                swap = 1;
            }
        }
        if (swap == 0)
        {
            return head;
        }
    }
    return head;
}

int main()
{
    Node *head = takeInput_Better();
    print(head);
    // cout << "BubbleSort call" << len(head);
    head = bubbleSort(head);
    print(head);
}