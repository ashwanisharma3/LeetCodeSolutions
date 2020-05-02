/*
Link: https://leetcode.com/problems/search-a-2d-matrix-ii/

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

// Solution
// Since the matrix is sorted row wise and column wise,
// Approach here is to search from the top right corner
// and go left until the smaller element is found and 
// then go downwards untill the greater element and repeat
// We break the process when the target element is found.

/*
TC = O(m + n) where m is size of row and n is size of columns
SC = O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (!m)
            return false;
        
        int n = matrix[0].size();
        int i = 0, j = n - 1;                           // we start from top right corner
        
        while (i < m && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            
            while (j >= 0 && matrix[i][j] > target)
                j--;
            if (j < 0)
                return false;
            while (i < m && matrix[i][j] < target)
                i++;
        }
        return false;
    }
};