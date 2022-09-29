#include<iostream>
using namespace std;
void shifting(char *arr){
    int size = sizeof(arr) / sizeof(char);
    for(size; size >= 1; size--){
        arr[size+1] = arr[size];
    }
    arr[1] = '*';
}


void starPair(char *str){
    if(str[1] == '\0'){
        return;
    }
    if(str[0] == str[1]){
        shifting(str);
        starPair(str+1);
        return; 
    }else starPair(str+1);
}


int main(){
    char str[] = "hellooooo";
    starPair(str);
    cout << str;
}