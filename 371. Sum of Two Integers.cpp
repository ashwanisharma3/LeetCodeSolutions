/*
Link: https://leetcode.com/problems/sum-of-two-integers/

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1
*/

// Solution
// Using the concept of bitwise XOR and Bitwise AND

/*
TC = O(1) the loop run maximum of 32 times for int
SC = O(1)
*/

class Solution {
    public int getSum(int a, int b) {
        int sum = a;
        // running the loop until b is zero
        while (b != 0)
        {
            sum = a ^ b;        // xor find the sum at every bit
            b = (a & b) << 1;   // find the carry, AND gets the carry and we left shift
                                // and add it to the sum obtained above
            a = sum;
        }
        
        return sum;
    }
}