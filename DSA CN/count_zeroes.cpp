#include<iostream>
using namespace std;

int count_zeroes(int num){
    if(num == 0){
        return 0;
    }
    if(num % 10 == 0){
        return 1 + count_zeroes(num/10);
    }
    return count_zeroes(num/10);
    
}

int main(){
    int a = 100;
    cout << count_zeroes(a);
}