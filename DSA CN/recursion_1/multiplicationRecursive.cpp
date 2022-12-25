/*

Given two integers M & N, calculate and return their multiplication using recursion. You can only use subtraction and addition for your calculation. No other operators are allowed.
Input format :
Line 1 : Integer M
Line 2 : Integer N
Output format :
M x N
Constraints :
0 <= M <= 1000
0 <= N <= 1000
Sample Input 1 :
3
5
Sample Output 1 :
15
Sample Input 2 :
4
0
Sample Output 2 :
0

*/

#include <iostream>
using namespace std;
int multiplication(int m, int n)
{
    int ans;
    if (n == 0)
    {
        return 0;
    }
    int smallOutput = multiplication(m, n - 1);
    ans = m + smallOutput;
    return ans;
}

int main()
{
    cout << "This program is for multiplication(Recursive). Plese enter the numbers a and b" << endl;
    5 int m = 0;
    int n = 0;
    cin >> m >> n;
    cout << "The answer is: " << multiplication(m, n) << endl;
}