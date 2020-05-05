/*
Link: https://leetcode.com/problems/factorial-trailing-zeroes/

Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Note: Your solution should be in logarithmic time complexity.
*/

// Solution


/*
TC = O(log n base 5)
SC = O(1) in iterative; recursion uses extra memory for execution, here it is O(log n base 5)
*/

class Solution {
public:
    int trailingZeroes(int n) {
        // This line is solution using recursion
        // return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);

        // Iterative
        int i = 1, ans = 0;
        while (1) {
            if (n / pow(5, i) < 1)
                break;
            ans += n / pow(5, i++);
        }
        
        return ans;
    }
};