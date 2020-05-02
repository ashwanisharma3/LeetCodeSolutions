/*
Link: https://leetcode.com/problems/flatten-2d-vector
https://www.lintcode.com/problem/flatten-2d-vector/description

Implement an iterator to flatten a 2d vector.

Example
Example 1:

Input:[[1,2],[3],[4,5,6]]
Output:[1,2,3,4,5,6]
Example 2:

Input:[[7,9],[5]]
Output:[7,9,5]
*/

// Solution
class Vector2D {
public:
    int col, row;
    vector<vector<int>>vec2d;
    Vector2D(vector<vector<int>>& v) {
        col = -1;
        row = 0;
        vec2d = v;
        // Initialize your data structure here
    }

    int next() {
        return vec2d[row][col];
        // Write your code here
    }

    bool hasNext() {
        col++;
        while (row < vec2d.size() && col >= vec2d[row].size()) {
            row++;
            col = 0;
        }
        return row < vec2d.size();
        // Write your code here
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */