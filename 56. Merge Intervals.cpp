/*
Link: https://leetcode.com/problems/merge-intervals/

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

// Solution
// Sort the vector by first index
// then, iterate and see if the next one can be merged

/*
TC = O(n log n)
SC = O(n)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        int i, j, len = v.size(), k = 0;
        if (!len)
            return v;
        sort (v.begin(), v.end());
        
        vector<vector<int>>ans;
        ans.push_back(v[0]);                            // storing the first row
        vector<int> temp = v[0];                        // first row
        
        for (i = 1; i < len; i++) {             
            if (ans[k][1] >= v[i][0]) {                 // if the last of previous row is greater than the start of current then it will be merged
                ans[k][1] = max (ans[k][1], v[i][1]);   // end index will be maximum of current end or previous end
            } else {
                ans.push_back(v[i]);
                k++;
            }
        }
        
        return ans;
    }
};