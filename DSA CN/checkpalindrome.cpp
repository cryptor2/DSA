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

bool palindrome(char str[]){

}

int main(){
    char str[] = "racecar";
    cout << size(str);
}