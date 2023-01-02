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

Node *evenAfterOdd(Node *head)
{
    Node *even = new Node(-1);
    Node *e = even;
    Node *odd = new Node(-1);
    Node *o = odd;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            e->next = temp;
            e = e->next;
            temp = temp->next;
            e->next = NULL;
        }
        else if (temp->data % 2 != 0)
        {
            o->next = temp;
            o = o->next;
            temp = temp->next;
            e->next = NULL;
        }
    }
    if (even != NULL && odd != NULL)
    {
        head = odd->next;
        o->next = even->next;
    }
    else if (even == NULL)
    {
        head == odd->next;
    }
    else if (odd == NULL)
    {
        head = even->next;
    }
    return head;
}

int main()
{
    Node *head = takeInput_Better();
    Node *headUpdated = evenAfterOdd(head);
    print(head);
}