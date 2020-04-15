/*
Link: https://leetcode.com/problems/power-of-three/

Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
Output: false
Follow up:
Could you do it without using any loop / recursion?
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        long long int x = 1;
        while(x < n) {
            x = x * 3;
        }
        if(x == n)
            return true;
        return false;
    }
};