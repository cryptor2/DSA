#include<iostream>
using namespace std;

void shift(char *str){
    for(int i=0; str[i] != '\0'; i++){
        str[i]= str[i+1];
        
    }
    return;
}

void removeX(char *str){
    if(str[0] == '\0'){
        return;
    }
    removeX(str+1);
    if(str[0] == 'x'){
        shift(str);
    }
}
int main(){
    char str[] = "xaxb";
    removeX(str);
    cout <<str;
}