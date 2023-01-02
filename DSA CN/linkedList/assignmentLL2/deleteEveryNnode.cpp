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

Node *deleteEveryNnode(Node *head, int m, int n)
{
    if (m == 0)
    {
        return NULL;
    }
    else if (n == 0)
    {
        return head;
    }
    else
    {
        int contain = m;
        int dlt = n;
        Node *temp = head;
        Node *tail = NULL;
        while (temp != NULL)
        {
            int i = 0;
            int j = 0;
            while (i < contain && temp != NULL)
            {
                tail = temp;
                temp = temp->next;
                i++;
            }
            while (j < dlt && temp != NULL)
            {
                Node *d = tail->next;
                if (temp != NULL)
                {
                    tail->next = tail->next->next;
                    temp = tail->next;
                    delete d;
                }
                else
                {
                    tail->next == NULL;
                    temp == NULL;
                    return head;
                }

                j++;
            }
        }
        return head;
    }
}

int main()
{
    Node *head = takeInput_Better();
    int m, n;
    cin >> m >> n;
    Node *headUpdated = deleteEveryNnode(head, m, n);
    print(headUpdated);
}