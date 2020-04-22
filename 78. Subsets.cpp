/*
Link: https://leetcode.com/problems/subsets/

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        findSubset(nums, 0, temp, ans);
        return ans;
    }
    
    void findSubset(vector<int> &nums, int start, vector<int> temp, vector<vector<int>> &ans) {
        
        ans.push_back(temp);
        
        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            findSubset(nums, i + 1, temp, ans);
            temp.pop_back();
        }
    }
};