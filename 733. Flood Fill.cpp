#MayChallenge #DFS
/*
Link: https://leetcode.com/problems/flood-fill/

An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/

// Solution
// Approach is to traverse through the matrix in the left, right, top and down direction of the target 
// coordinates recursively.
/*
TC = O(n)
SC = O(n) where is the total number of element in the matrix.
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        if (m == 0)
            return image;
        int n = image[0].size();
        
        
        fill(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
    
    void fill( vector<vector<int>>&image, int r, int c, int x, int color) {
        if (r < 0 
        || r >= image.size() 
        || c < 0 
        || c >= image[0].size()
        || image[r][c] != x 
        || image[r][c] == color
        )
            return;
        
        image[r][c] = color;
        fill (image, r, c + 1, x, color);
        fill (image, r, c - 1, x, color);
        fill (image, r + 1, c, x, color);
        fill (image, r - 1, c, x, color);
    }
};