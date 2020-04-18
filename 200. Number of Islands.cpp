/*
Link: https://leetcode.com/problems/number-of-islands/

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

//Solution 1 Using DFS

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int i, j, m, n;
        m = grid.size();
        
        if(!m)
            return 0;
        
        n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int> (n, 0));
        
        int count = 0;
        
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    DFS (grid, visited, i, j);
                    count ++;
                }
            }
        }
        return count;
    }
    
    void DFS (vector<vector<char>>& grid, vector<vector<int>> &visited, int row, int col) {
        int r[4] = {0, 0, -1, 1};
        int c[4] = {-1, 1, 0, 0};
        
        visited[row][col] = 1;
        
        for (int i = 0; i < 4; i++) {
            if (isTrue (grid, visited, row + r[i], col + c[i])) {
                DFS (grid, visited, row + r[i], col + c[i]);
            }
        }
    }
    
    bool isTrue (vector<vector<char>>& grid, vector<vector<int>> &visited, int row, int col) {
        return row >= 0 && col >= 0 
            && row < grid.size() 
            && col < grid[0].size() 
            && !visited[row][col] 
            && grid[row][col] == '1';
    }
};