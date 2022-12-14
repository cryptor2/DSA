#include<iostream>
using namespace std;

int partition(int arr[], int si,  int ei){
    int pivet = arr[si];
    int count = 0;
    for(int i = si+1; i <= ei; i++ ){
        if(pivet > arr[i]){
            count++;
        }
    }
    int c = si + count;
    arr[si] = arr[c];
    arr[c] = pivet;

    int i = si;
    int j = ei;

    while(i < c && j > c){
        if(arr[i] < pivet){
            i++;
        }else if(arr[j] >= pivet){
            j++;
        }else{
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return c;
}


void quickSort(int arr[], int si, int ei){
    if(si >= ei){
        return;
    }
    int c = partition(arr,si , ei );
    quickSort(arr, si, c-1);
    quickSort(arr, c+1, ei);
}
int main(){
    int arr[] = {10,10,3,12,14,6,2};
    quickSort(arr, 0, 5);
    for(int i =0; i <=5 ; i++){
        cout << arr[i] << " ";
    }
}