#include<iostream>
#include<stack>
#include<queue>

using namespace std;


/*int* stockSpan(int arr[],int size){
    stack<int> s;
    queue<int> q;
    for (int i = 0; i < size; i++){
        s.push(arr[i]);
    }
    int TempSize = size;
    for (int i = 0; i < size ;i++){
        int data = s.top();
        s.pop();
        TempSize--;
        int ans = 1;
        for (int j = 0; j < TempSize; j++){
            int top = s.top();
            s.pop();
            s.push(top);
            if(top < data)
                ans++;
            else
                break;
        }
        q.push(ans);
    }
    for (int i = 0; i < size; i++){
        cout << q.front() << " ";
        q.pop();
    }
    return NULL;
}*/

int * stockSpan(int arr[], int n){
    stack<int> s;
    // s.push(0);
    int *span = new int[n];
    for (int i = 0; i < n; i++){
        while(!s.empty() && arr[s.top()] < arr[i])
            s.pop();
        if(s.empty())
            span[i] = i + 1;
        else
            span[i] = i - s.top();
        s.push(i);
    }
    return span;
}

int main(){
    int arr[] = {10,10,10,10};
    int size = 4;
    int * span = stockSpan(arr, size);
    for (int i = 0; i < size; i++)
        cout << span[i] << " ";
}