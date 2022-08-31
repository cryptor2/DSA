#include<iostream>
using namespace std;

int size(char str[]){
    int i = 0;
    while(str[0] != '\0'){
        i++;
        str++;
    }
    return i;
}

bool palindrome(char str[], int si, int ei){
    if(si == ei){
        return true;
    }
    else if(str[si] == str[ei]){
        palindrome(str, si+1, ei-1);
    }else{
        return false;
    }
}

int main(){
    char str[] = "racecar";
    int sz = size(str);
    if(palindrome(str, 0, sz-1)){
        cout << "true";
    }else{
        cout << "false";
    }
}