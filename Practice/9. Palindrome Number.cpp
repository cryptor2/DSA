/*********************************************************
 * (04/10/23)
 *
 *                      Day - 1
 *
 *
 Given an integer x, return true if x is a palindrome, and false otherwise.

 Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.


***********************************************************/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        string s = to_string(x);
        int j = s.size() - 1;
        int i = 0;
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};