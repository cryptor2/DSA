#include<iostream>
using namespace std;

int x_to_the_power_n(int x, int n){
    if(n == 1){
        return x;
    }
    int result = x * x_to_the_power_n(x, n-1);
    return result;
}
int main(){
    int x,n;
    cout << "enter the numbers" << endl;
    x = 2 , n = 3;
    cout << x_to_the_power_n(x,n) << endl;
}