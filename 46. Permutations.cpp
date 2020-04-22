/*
Link: 

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        findPermutations(nums, ans, 0);
        return ans;
    }
    
    void findPermutations (vector<int> nums, vector<vector<int>> &ans, int start) {
        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for(int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            findPermutations(nums, ans, start + 1);
            swap(nums[i], nums[start]);
        }
    }
};