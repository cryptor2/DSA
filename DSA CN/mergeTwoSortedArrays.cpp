#include<iostream>
using namespace std;
void mergeTwoSortedArrays(int arr1[], int arr2[], int result[], int size1, int size2, int sizeResult){
    int a = 0;
    int b = 0;
    int res = 0;
    for(; res < sizeResult; res++){
        
        if(a == size1){
            for(; b <= size2; b++){
                result[res] = arr2[b];
                res++;
                
            }
        }

        else if(b == size2){
            for(; a <= size1; a++){
                result[res] = arr1[a];
                res++;
            }
        }
        
        else if(arr1[a] < arr2[b]){
            result[res] = arr1[a];
            a++;
        }
        else if(arr2[b] < arr1[a]) {
            result[res] = arr2[b];
            b++;
        }

    }

}

int main(){
    int arr1[] = {1,3,5};
    int arr2[] = {0,2,2};
    int result[5] = {0};
    mergeTwoSortedArrays(arr1, arr2, result,3,3,6);
    for(int i =0; i < 6; i++){
        cout << result[i] << " ";
    }

}