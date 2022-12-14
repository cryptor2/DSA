#include<iostream>
using namespace std;

int number_of_digits(int n){
    if(n < 10){
        return 1;
    }

    int count = number_of_digits(n/10) + 1;
    return count;
}
int main(){
    int x = 10;
    cout << number_of_digits(x);
}
