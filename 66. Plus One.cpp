/*
Link: https://leetcode.com/problems/plus-one/

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i, k, n = digits.size(), carry = 1;         // intialising carry as 1, as we need to add 1 to the number
        
        for(i = n - 1; i >= 0; i--) {                   // iterating from the end of the array
            k = (digits[i] + carry);                    // adding carry to the digit
            carry = k / 10;                             // finding the next carry
            digits[i] = k % 10;                         // storing the new digit for the index
        }
        if(carry) {                                     // if there still exists a carry
            digits.insert(digits.begin(), carry);       // insert the carry to the front of the vector
        }
        return digits;
    }
};

/*
TC = O(n)
SC = O(1)
