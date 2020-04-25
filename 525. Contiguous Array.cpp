/*
Link: https://leetcode.com/problems/contiguous-array/

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int i, c = 0, n = nums.size(), ans = 0;
        
        map<int, int> mp;
        mp[0] = -1;
        for (i = 0; i < n; i++) {
            nums[i] ? c++ : c--;
                
            if(mp.find(c) != mp.end()) {
                ans = max (ans, abs(mp[c] - i));
            } else {
                mp[c] = i;
            }
        }
        return ans;
        
    }
};