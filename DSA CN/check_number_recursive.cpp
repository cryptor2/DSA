#include<iostream>
using namespace std;
bool checking(int arr[], int size, int check){
    if(arr[0] == check){
        return true;
    }
    if(size==0 && arr[0] != check){
        return false;
    }
    return checking(arr+1, size-1, check);
    
}

int main(){
    int size = 8;
    int check = 3;
    int arr[] = {4,2,7,8,9,0,5,1};
    cout << checking(arr, size-1, check);
}
