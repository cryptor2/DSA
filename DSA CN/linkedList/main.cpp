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
        for (int pos = 1; pos < i && temp != NULL; pos++)
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

// delete node from specific postion
Node *deleteNode(Node *head, int i)
{

    Node *temp = head;
    if (head == NULL)
    {
        return head;
    }
    else if (i == 0)
    {
        head = temp->next;
        delete temp;
        return head;
    }
    else if (head != NULL & i > 0)
    {
        for (int pos = 1; pos < i && temp != NULL; pos++)
        {
            temp = temp->next;
        }
        Node *last = temp->next;
        temp->next = temp->next->next;
        delete last;
        return head;
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

int length(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
    }
}

int printINode(Node *head, int i)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
    }
}

// int main()
// {
//     Node *head = takeInput_Better();
//     print(head);
//     int i = 1;
//     head = insertNode(head, i, 99);
//     print(head);
// }