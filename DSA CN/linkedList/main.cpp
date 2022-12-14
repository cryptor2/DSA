#include <iostream>
#include "node.cpp"
using namespace std;

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

// insert node at specific postition...
Node *insertNode(Node *head, int i, int data)
{
    Node *temp = head;
    if (i == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    else if (head == NULL)
    {
        return head;
    }
    else if (head != NULL && i > 0)
    {
        for (int pos = 0; pos < i && temp != NULL; pos++)
        {
            temp = temp->next;
        }
        if (temp != NULL)
        {
            Node *newNode = new Node(data);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = takeInput_Better();
    print(head);
}