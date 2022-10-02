#include<iostream>
using namespace std;
void repalceChar(char str[],char a,char b){
    if(str[0] == '\0'){
        return;
    }
    if(str[0] == a){
        str[0] = b;
    }
    repalceChar(str+1, a, b);
}
int main(){
    char str[] = "luck";
    char a = 'l';
    char b = 'e';
    repalceChar(str, a, b);
    cout << str;
}