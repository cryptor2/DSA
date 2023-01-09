#include <iostream>
#include <queue>
using namespace std;
void reverseQueue(queue<int> &input)
{
    // Write your code here
    if (input.size() == 0)
        return;
    int ans = input.front();
    input.pop();
    reverseQueue(input);
    input.push(ans);
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    reverseQueue(q);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
}