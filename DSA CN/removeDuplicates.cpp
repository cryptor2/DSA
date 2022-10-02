#include<iostream>
using namespace std;

void removeElement(char str[]){
    int i = 1;
    while(str[i] != '\0'){
        str[i]= str[i+1];
        i++;
    }
}

void removeDuplicates(char str[]){
    if(str[0] == '\0'){
        return; 
    }
    if(str[0] == str[1]){
        removeElement(str);
    }
    removeDuplicates(str+1);
}

int main(){
    char str[] = "aabccba";
    removeDuplicates(str);
    cout << str;
}