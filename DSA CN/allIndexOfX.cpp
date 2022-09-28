#include<iostream>
using namespace std;

int allIndexI(int *arr, int size, int x, int *output){
    if(size == 0){
        return 0;
    }
    int smallOut = allIndexI(arr+1, size-1, x, output);
    if(arr[0] == x){
        for(int i = smallOut-1; i>=0; i-- ){
            output[i+1] = output[i] + 1;
        }
        output[0] = 0;
        smallOut++;
    }else{
            for( int i = smallOut-1; i>=0; i-- ){
            output[i] = output[i] +1;
        }
    }
    return smallOut;

}

int main(){
    int arr[] = {1,1,2,3};
    int out[4];
    int size = 4;
    int x=1;
    int s2 = allIndexI(arr,size,x,out);
    for(int i=0; i < s2; i++){
        cout << out[i];
    }
}