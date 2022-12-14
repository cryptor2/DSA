#include<iostream>
using namespace std;

int firstIndex(int *arr,int num, int size){
    if(size == 0){
        return -1;
    }
    if(arr[0] == num){
        return 0;
    }
    int index = firstIndex(arr+1, num, size-1) + 1;
    return index;

}

int main(){
    int arr[]= {5,5,7,7,8,8,6,7};
    cout << firstIndex(arr, 6,8 );
}