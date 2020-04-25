/*
Link:

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0
*/

//Solution 1
// As n & n -1 is less than or equal to n - 1
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int cnt = 0;
        while(m < n) {
            n = n & (n - 1);
        }
        return m & n;
    }
};

//Solution 2
// Approach here is to shift m & n till the time they are equal 
// as at the places where their bits are different then the digit
// at that place will zero.
// this also uses the fact that AND of even and odd number makes
// LSB zero.
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int cnt = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            cnt ++;
        }
        
        return m << cnt;
    }
};

