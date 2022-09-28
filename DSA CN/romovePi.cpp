#include<iostream>
#include <cstring>
using namespace std;

void shiftArray(char *str){
    int i = 0;
    int s = strlen(str);
    while(i < s){
        str[s+2] = str[s];
        s--;
    }
}

void removePi(char *str){
    if(str[1] =='\0' || str[0]== '\0'){
        return;
    }
    removePi(str+1);
    if(str[0] == 'p' && str[1] == 'i'){
        shiftArray(str);
        str[0] = '3';
        str[1]= '.';
        str[2]='1';
        str[3]= '4';
    }
}
int main(){
    char str[] = "pip";
    removePi(str);
    cout << str;
}
