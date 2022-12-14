#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    for(int i = 0; i <7; i++){
        int temp= arr[i+1]; 
        arr[i+1] = arr[i];
            
    }
}