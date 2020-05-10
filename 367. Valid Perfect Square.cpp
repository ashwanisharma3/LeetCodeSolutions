/*
Link: https://leetcode.com/problems/valid-perfect-square/

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
*/

// Solution
// We use the approach sum of first n odd numbers is equal to the nth square.

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0)
            return false;
        
        int i = 1;
        
        while (num > 0) {
            num -= i;
            i += 2;
        }
        
        return num == 0;
    }
};