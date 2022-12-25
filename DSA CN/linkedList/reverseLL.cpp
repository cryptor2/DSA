#include <iostream>
#include "main.cpp"
// worst one approch
// time complexity O(n2)
// Node *reverseLL(Node *head)
// {
//     if (head == NULL || head->next == NULL)
//     {
//         return head;
//     }

//     Node *smallOutput = reverseLL(head->next);
//     Node *temp = smallOutput;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = head;
//     head->next = NULL;
//     head = smallOutput;
//     return head;
// }
///////////////////////////////////////////////////////
// better approach
//  tn o(n)

class Pair
{
public:
    Node *head;
    Node *tail;
};

Pair reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallOut = reverseLL(head->next);
    smallOut.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallOut.head;
    ans.tail = head;
    return ans;
}

Node *reverseLLRun(Node *head)
{
    Pair ans = reverseLL(head);
    return ans.head;
}
int main()
{
    Node *head = takeInput_Better();
    // print(head);
    Node *temp = reverseLLRun(head);
    print(temp);
}
