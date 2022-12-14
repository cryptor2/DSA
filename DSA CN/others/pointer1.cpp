#include <iostream>
using namespace std;

int main() {
  cout << "Hello World!";
  int a[] = {0,1,2,3};
  char s[]= "hello";
  char *p = s;
  cout << s[0] << " " << p[0];
  return 0;
}