/*
Link: https://leetcode.com/problems/set-matrix-zeroes/submissions/

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

// Solution
/*
TC = O(n x m)
SC = O(1)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i, j, flagC = 0, m = matrix.size(), n = matrix[0].size();
        
        if(!m || !n)
            return;

        
        for (i = 0; i < m; i++) {
            
            if (!matrix[i][0]) {                        // if the first column if to be set to zero
                flagC = 1;
            }
            
            for (j = 1; j < n; j++) {
                if (!matrix[i][j]) {                    // if zero then,
                    matrix[0][j] = 0;                   // setting the top column element to zero
                    matrix[i][0] = 0;                   // setting the left most element of row to zero
                }
            }
        }
        
        for (i = 1; i < m; i++) {
                for (j = 1; j < n; j++) {
                    if (!matrix[i][0] || !matrix[0][j]) // if the first index in the respective row and column is zero
                        matrix[i][j] = 0;
                }
        }
        
        if (! matrix[0][0]) {                           // setting first row to zero
            for (j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        
        if (flagC) {                                    // setting the first column to zero
            for ( i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};