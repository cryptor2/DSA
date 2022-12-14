#include<iostream>
using namespace std;

string keyword(int n){
    string keypad[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    return keypad[n];

}
int returnKeypad(int n, string output[]){
    if(n == 0){
        output[0] = "";
        return 1;
    }
    int smallCalc = returnKeypad(n/10, output);
    int btn = n % 10;
    string str = keyword(btn);
    int k = smallCalc* str.length();
    for(int i = 0; i< k; i++){
        output[i] = output[i%smallCalc];
    }
    for(int j = 0; j< k; j++){
        output[j] = output[j]+str[j/smallCalc];
    }
    return k;
}

int main(){
    int n;
    cin >> n;
    string* output = new string[1000];
    int keypad = returnKeypad(n , output); 
    for(int i = 0; i < keypad; i++){
        cout << output[i] << endl;
    }
}