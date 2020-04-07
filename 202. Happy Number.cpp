/*
Link: https://leetcode.com/problems/happy-number/

Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
*/

class Solution {
public:
    bool isHappy(int n) {
        int i, j, x = n, t;
        set <int> myset;
        while(1) {									// running the loop until either number becomes zero
        											// or numbers start repeating
            t=0;
            while (x) {								// extracting all the digits
                t = t + pow(x % 10, 2);				// sqauring the digits and adding them
                x = x/10;
            }
            
            if(t == 1) {							// if number become 1 return true
                return true;
            } 
            if (myset.find(t) != myset.end()) {		// finding in the map if the number exists
                return false;						// if exists means that number have started to repeat
            }
            myset.insert(t);						// inserting in the map
            x=t;
        }
    return false;
    }
};