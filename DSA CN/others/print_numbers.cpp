#include<iostream>
using namespace std;

int count(int n){
    if (n==0){
        return 0;
    }
    int result = count(n-1) + 1;
    cout << result << " ";
    return result;
}
int main(){
    int n; 
    n =5;
    count(n);
}