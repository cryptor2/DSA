#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

Node *insertAtHead(Node *&head, int val)
{
    // if (head == NULL)
    // {
    //     Node *n = new Node(val);
    //     head = n;
    //     return;
    // }
    // else
    // {
    Node *temp = head;
    Node *n = new Node(val);
    n->next = head;
    if (head != NULL)
        head->prev = n;
    head = n;
}

// insert at tail.
void insertAtTail(Node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    Node *n = new Node(val);
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);
    display(head);
}
