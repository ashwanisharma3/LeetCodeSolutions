/*
Link: https://leetcode.com/problems/divide-two-integers/

Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
*/

// Solution
// We subtract the sum of all powers of two less than the current dividend from it.
// and repeat the process untill dividend is less than divisor.

/*
TC = O(1)
SC = O(1)
*/

class Solution {
public:
    int divide(long long int dividend, long long int divisor) {
        
        long long ans = 0, temp = 1;
        
        int flag = (divisor < 0 ^ dividend < 0);
        
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        while (dividend >= divisor) {
            long long int temp = 1;
            ans += temp;
            long long int div = divisor;   
            dividend -= divisor;
            while (dividend >= divisor << 1) {
                divisor <<= 1;
                dividend = dividend - divisor;
                temp <<= 1;
                
                ans += temp;
            }
            
            divisor = div;
        }
        if (flag)
            return -ans;
        return ans;
    }
};