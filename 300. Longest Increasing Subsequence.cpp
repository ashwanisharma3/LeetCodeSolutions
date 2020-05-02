/*
Link: https://leetcode.com/problems/longest-increasing-subsequence/

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/
/*
TC = O(n ^ 2)
SC = O(n)

For TC = O(n log n) use binary search.
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int i, j, len = nums.size();
        
        if(!len)
            return 0;
        
        int dp[len];
        
        dp[0] = 1;
        int max_so_far = 1;
        int curr_len = INT_MIN;
        for (i = 1; i < len; i++) {                     // from left to right
            curr_len = 0;
            for (j = i - 1; j >= 0; j--) {              // searching if there is a smaller number with longest subsequence
                if (nums[j] < nums[i]) {
                    curr_len = max (curr_len, dp[j]);
                }
            }
            dp[i] = curr_len + 1;
            max_so_far = max(max_so_far, dp[i]);
        }
        return max_so_far;
    }
};

// For