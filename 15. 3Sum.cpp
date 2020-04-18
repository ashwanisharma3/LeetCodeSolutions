/*
Link: https://leetcode.com/problems/3sum/

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
// Approach here is to use two pointer. This is kind of similar to two sum.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        set<vector<int>> s;

        vector<vector<int>> ans;
        
        int i, j, k, len = nums.size();
        
        for (i = 0; i < len - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1])                  // if adjacent elements are equal
                continue;

            j = i + 1;                                          // 1st pointer, next of i
            k = len - 1;                                        // 2nd pointer from the end of vector
            
            while(j < k) 
            {
                if(nums[i] + nums[j] + nums[k] == 0)            // if the sum of all elements at i, j, k == 0
                {
                    vector<int> v = {nums[i], nums[j], nums[k]};
                    
                    s.insert(v);                                // using set to avoid duplicate
                    
                    while (j < k && nums[j] == nums[j+1]) {     // if the adjacent elements are equal
                        j++;
                    }

                    while (k > j && nums[k] == nums[k-1]) {     // if the adjacent elements are equal   
                        k--;
                    }

                    j++;
                    k--;
                } 
                else if(nums[i] + nums[j] + nums[k] > 0)        // if sum is greater than 0, then move towards the less value
                {
                    k--;
                } 
                else 
                {
                    j++;
                }
            }
        }

        for (auto it = s.begin(); it != s.end(); it++) {
            ans.push_back(*it);
        }
        return ans;
    }
};