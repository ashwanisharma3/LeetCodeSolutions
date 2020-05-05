/*
Link: https://leetcode.com/problems/majority-element/

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

// Solution

/*
TC = O(n)
SC = O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int current;
        
        for (int i : nums) {
            if (count == 0)
                current = i;                            // the current major number
            count += (i == current) ? 1 : -1;           // if the element is not major or it is major
        }
        return current;
    }
};