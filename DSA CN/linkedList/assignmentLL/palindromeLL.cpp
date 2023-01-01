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

Node *ReverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *smallOut = ReverseLL(head->next);

    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return smallOut;
}
bool checkPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    else
    {
        Node *temp = head;
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *h2 = slow;
        h2 = ReverseLL(h2);
        Node *temp2 = h2;
        while (temp->next != slow)
        {
            temp = temp->next;
        }
        temp->next = NULL;

        temp = head;
        while (temp != NULL && temp2 != NULL)
        {
            if (temp->data == temp2->data)
            {
                temp = temp->next;
                temp2 = temp2->next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
}

int main()
{
    Node *head = takeInput_Better();
    // checkPalindrome(head);
    cout << checkPalindrome(head);
}