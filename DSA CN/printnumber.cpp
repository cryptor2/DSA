#include<iostream>
using namespace std;

void printNumber(int n){
    if(n==0){
        return;
    }
    cout << printNumber(n-1);
}

int main(){

}