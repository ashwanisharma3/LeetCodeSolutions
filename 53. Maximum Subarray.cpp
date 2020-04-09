/*
Link: 

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

*/

class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int i, j, n = a.size();
        
        int maxSoFar = a[0], currMax = a[0];
        
        for (i = 1; i < n; i++) {
            currMax = max(a[i], a[i] + currMax);
            maxSoFar = max(maxSoFar, currMax);
        }
        
        return maxSoFar;
        return 0;
    }
};