#include<iostream>
using namespace std;

int lastIndex(int *arr, int size, int num){
    if(size == 0){
        return -1;
    }
    int ans = lastIndex(arr+1, size-1, num);
    if (ans >= 0){
        return ans+1;
    }else if(arr[0] == num){
        return 0;
    }else return ans;
    

}

int main(){
    int arr[]= {5,5,7,7,8,8,6,7};
    cout << lastIndex(arr, 8,77);
}