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
Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *smallAns = reverse(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return smallAns;
}

Node *reverseKNode(Node *head, int n)
{
    Node *h1 = head;
    Node *h2 = NULL;
    int i = 1;
    while (i < n)
    {
        h1 = h1->next;
        i++;
    }
    h2 = h1->next;
    h1->next = NULL;
    h1 = reverse(head);
    head = h1;
    while (h1->next != NULL)
    {
        h1 = h1->next;
    }
    h1->next = h2;
    return head;
}

int main()
{
    Node *head = takeInput_Better();
    head = reverseKNode(head, 4);
    print(head);
}