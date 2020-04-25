/*
Link: https://leetcode.com/problems/subarray-sum-equals-k/

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i, len = nums.size(), sum = 0, count= 0;
        
        map<int, int> mp;
        mp[0] = 1;
        
        for(int i : nums) {
            sum += i;
            
            if (mp[sum - k]) {
                count += mp[sum - k];
            }
            
            mp[sum]++;
        }
        return count;
    }
};