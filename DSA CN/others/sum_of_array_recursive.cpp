#include<iostream>
using namespace std;
int sum(int arr[], int size){
    if(size == 0){
        return arr[0];
    }
    int add = sum(arr+1, size-1)+ arr[0];
    return add;
}

int main(){
    int size = 3;
    int arr[] = {9,8,9};
    cout << sum (arr,size-1);
}
