/*
Link: https://leetcode.com/problems/climbing-stairs/

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)                             // if n == 1
            return 1;
        int i, step[n];
        step[0] = 1;                            // intialising
        step[1] = 2;                            // intialising
        for (i = 2; i < n; i++) {
            step[i] = step[i - 1] + step[i -2]; // DP
        }
        return step[n-1];
    }
};