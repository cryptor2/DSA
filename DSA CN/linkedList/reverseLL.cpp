#include <iostream>
#include "main.cpp"

Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *smallOutput = reverseLL(head->next);
    Node *temp = smallOutput;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    head = smallOutput;
    return head;
}

int main()
{
    Node *head = takeInput_Better();
    // print(head);
    Node *temp = reverseLL(head);
    print(temp);
}
