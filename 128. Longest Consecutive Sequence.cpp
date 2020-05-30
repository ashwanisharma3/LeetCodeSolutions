#array #string #unionFind
/*
Link: https://leetcode.com/problems/longest-consecutive-sequence/

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

// Solution
// Approach to look for the position of the current number. There can be 3 cases:


/*
TC = O(n)
SC = O(n)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        int ans = 0;
        for(int i : nums) {
            if (!mp[i]) {
                int left = mp[i - 1];
                int right = mp[i + 1];
                
                int X = left + right + 1;
                
                mp[i] = X;
                ans = max(ans, X);
                mp[i - left] = X;
                mp[i + right] = X;
            }
        }
        return ans;
    }
};