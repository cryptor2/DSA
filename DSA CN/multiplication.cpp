#include<iostream>
using namespace std;
int multiplication(int n, int m){
    if(m == 1){
        return n;
    }
    if(m == 0){
        return 0;
    }
    return n + multiplication(n,m-1);
}
int main(){
    cout << multiplication(3,5);
}