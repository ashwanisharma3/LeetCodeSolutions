/*

Link: https://leetcode.com/problems/missing-ranges

Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.
Example:
Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]

*/

#include<vector>
class Solution {
public:
    /*
     * @param nums: a sorted integer array
     * @param lower: An integer
     * @param upper: An integer
     * @return: a list of its missing ranges
     */
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        int i = 1, j, len = nums.size();
        
        vector<string> ans;
        if(!len) {
            ans.push_back(getRange(lower, upper));
            return ans;
        }
        string s;
        
        for (; i < len; i++) {

            if (i == 0 && nums[0] > lower) {
                ans.push_back(getRange(lower, nums[0] - 1));
            }

            if(i - 1 > 0 && nums[i] != nums[i -1] && nums[i] != nums[i - 1] + 1) {
                s = getRange(nums[i - 1] + 1, nums[i] - 1);
                ans.push_back(s);
            }

            if (nums[len - 1] < upper) {
                s = getRange(nums[len - 1] + 1, upper);
                ans.push_back(s);
            }
        }
        return ans;
    }
    
    string getRange (int i, int j) {
        if (i == j) {
            return to_string(i);
        }
        
        return to_string(i) + "->" + to_string(j);
    }
};