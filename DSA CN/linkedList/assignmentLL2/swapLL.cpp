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

Node *swapLL(Node *head, int n, int m)
{
    if (head == NULL)
        return NULL;
    int i, k;
    Node *c1 = head;
    Node *c2 = NULL;
    Node *p1 = head;
    Node *p2 = NULL;
    if (n == 0)
    {
        i = 1;
        k = m;
        while (i < k)
        {
            p1 = p1->next;
            i++;
        }
        c2 = p1->next;
        p1->next = p1->next->next;
        c2->next = head->next;
        head = c2;
        c1->next = p1->next;
        p1->next = c1;
    }
    else if (n - m == 1 || n - m == -1)
    {
        i = 1;
        int k;
        if (n < m)
            k = n;
        else
            k = m;
        while (i < k)
        {
            p1 = p1->next;
            i++;
        }
        c1 = p1->next;
        p1->next = p1->next->next;
        c1->next = p1->next->next;
        p1->next->next = c1;
    }
    else
    {

        Node *temp = head;
        if (n < m)
            k = m;
        else
            k = n;
        i = 1;
        while (i <= k)
        {
            if (i == (n - 1))
            {
                p1 = temp;
                cout << "p1 " << temp->data << endl;
            }
            if (i == (m))
            {
                p2 = temp;
                cout << "p2 " << temp->data << endl;
            }
            temp = temp->next;
            i++;
        }
        c1 = p1->next;
        c2 = p2->next;

        p1->next = c1->next;
        c1->next = c2->next;
        p2->next = c1;
        c2->next = p1->next;
        p1->next = c2;
    }
    return head;
}
// 1 2 3 4 5 6 7 8 -1
int main()
{
    Node *head = takeInput_Better();
    // Node *head2 = takeInput_Better();

    Node *finalhead = swapLL(head, 1, 5);
    print(finalhead);
}