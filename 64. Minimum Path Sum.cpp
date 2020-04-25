/*
Link: https://leetcode.com/problems/minimum-path-sum/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), i, j;
        if (!m)
            return 0;
        int n = grid[0].size();
        
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (i == 0 && j != 0) 
                    grid[0][j] =  grid[0][j] + grid[0][j-1];
                else if (i!=0 && j == 0)
                    grid[i][0] = grid[i][0] + grid[i-1][0];
                else if (i != 0 && j != 0)
                    grid[i][j] = grid[i][j] + ((grid[i-1][j] > grid[i][j-1]) ? grid[i][j -1] : grid[i-1][j]);
            }
        }
        
        return grid[m-1][n-1];
    }
    
    
};