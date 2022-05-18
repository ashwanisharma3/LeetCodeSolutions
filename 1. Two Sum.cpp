/*
Link: https://leetcode.com/problems/two-sum/

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
File updated
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        int i = 0, j = n - 1;
        map<int, int>myMap;
        vector <int> ans;
        for (i = 0; i < n; i++) {
            if (myMap[target - nums[i]]) {
                ans.push_back(i);
                ans.push_back(myMap[target - nums[i]]);
                return ans;
            }
            myMap[nums[i]] = i;                 // saving the index of all numbers
        }
        return ans;
    }
};
