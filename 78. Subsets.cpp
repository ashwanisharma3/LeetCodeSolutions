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
// Using Back Tracking

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

// Using Bit Masking
// We are using the binary form of a the decimal number.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int i, len = nums.size();
        
        for(i = pow(2, len); i < pow(2, len + 1); i++) {
            string s = toBinary(i);
            for (int j = 0; j < s.size() - 1; j++) {
                if (s[j] == '1')
                    temp.push_back(nums[j]);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
    
    string toBinary (int n) {
        string ans = "";
        
        while (n) {
            if (n % 2) {
                ans += "1";
            } else
                ans += "0";
            
            n /= 2;
        }
        return ans;
    }
};