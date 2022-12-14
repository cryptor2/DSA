#include<iostream>
#include <string.h>

using namespace std;

int power(int pow){
    int val = 10;
    for(int i = 1; i <pow; i++){
        val*=10;
    }
    // cout<< val<< endl;
    return val;
}

int stringToInt(char arr[]){
    if(arr[0] == '\0'){
        return 0;
    }
    if(arr[1] == '\0'){
        return arr[0]-'0';
    }
    
    int ans = stringToInt(arr+1);
    int b = arr[0]-'0';
    int len = strlen(arr);
    return power(len-1)*b +ans;


}


int main(){
    char arr[] = "13479";
    cout << stringToInt(arr);
}

// techunlock