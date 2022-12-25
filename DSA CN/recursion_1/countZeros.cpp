/*

Given an integer N, count and return the number of zeros that are present in the given integer using recursion.
Input Format :
Integer N
Output Format :
Number of zeros in N
Constraints :
0 <= N <= 10^9
Sample Input 1 :
0
Sample Output 1 :
1
Sample Input 2 :
00010204
Sample Output 2 :
2
Explanation for Sample Output 2 :
Even though "00010204" has 5 zeros, the output would still be 2 because when you convert it to an integer, it becomes 10204.
Sample Input 3 :
708000
Sample Output 3 :
4

*/

#include <iostream>
using namespace std;

int countZeroes(int n)
{
    if (n < 10)
    {
        if (n == 0)
        {
            return 1;
        }
        else
            return 0;
    }

    int rem = n % 10;
    n = n / 10;
    int smallOutput = countZeroes(n);
    if (rem == 0)
    {
        return smallOutput + 1;
    }
    else
        return smallOutput;
}

int main()
{
    int n = 0;
    cin >> n;
    cout << countZeroes(n) << endl;
}