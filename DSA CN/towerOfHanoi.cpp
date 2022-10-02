#include<iostream>
using namespace std;
void towerOfHanoi(int n, char fromRod, char toRod, char helper){
    if(n==0){
        return;
    }
    towerOfHanoi(n-1, fromRod, helper, toRod);
    cout << "from " << fromRod << " toRod " << toRod<< endl;
    towerOfHanoi(n-1, helper, toRod, fromRod);
}

int main(){
    int n =3;
    towerOfHanoi(n, 'a', 'c', 'b');
}