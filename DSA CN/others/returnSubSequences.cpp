#include<iostream>
using namespace std;

int sub(string str,string output[]){
    if(str.empty()){
        output[0] = "";
        return 1;
    }
    string substring = str.substr(1);
    int smallOutputSize = sub(substring, output);
    for(int i =0; i < smallOutputSize; i++){
        output[i+smallOutputSize] = str[0] + output[i];
    }
    return 2 * smallOutputSize;
}

int main(){
    string str = "abc";
   
    int length = str.length();
    string* output = new string[100];
    int count = sub(str, output);

    for(int i = 0; i < count; i++){
        cout << output[i] << endl;
    }
}