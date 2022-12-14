#include<iostream>
#include <math.h>

using namespace std;
int power(int n){
    return pow(2, n);
    
}

double geomatricSum(int n){
    if (n==0){
        return 1;
    }
    double power1 = 1.00/power(n);
    return power1 + geomatricSum(n-1);

}
int main(){
    int n = 3;
    cout << geomatricSum(3);
}
