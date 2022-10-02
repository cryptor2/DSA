#include<iostream>
using namespace std;

void merge(int arr[], int si, int ei){
    int mid = (si + ei)/2;
    int size = ei - si +1;
    int temp[size] = {0};
    int a = si;
    int b = mid+1;
    int i = 0;
    while(a <= mid && b <= ei){
        if(arr[a] <= arr[b]){
            temp[i] = arr[a];
            a++;
            i++;
        }
        else if(arr[b] < arr[a]){
            temp[i] = arr[b];
            b++;
            i++;
        }
        
    }
    while(a <= mid){
        temp[i] = arr[a];
        i++;
        a++;
    }
    while ( b <= ei)
    {
        temp[i]= arr[b];
        i++;
        b++;
    }

    for(int i =0; i <size ; i++){
        arr[si+i] = temp[i];
    }
    
}


void mergeSort(int arr[], int si, int ei){
    if(si >= ei){
        return;
    }
    int mid = (si + ei) / 2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);
    merge(arr, si, ei);
}

int main(){
    int arr[]= {2 ,60, 8, 5, 4, 3,7};
    mergeSort(arr,0, 6);
    for(int i = 0; i < 7; i++){
        cout << arr[i] << " ";
    }
}