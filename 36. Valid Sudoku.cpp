/*
Link: https://leetcode.com/problems/valid-sudoku/

Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.
*/
#include<vector>

class Solution {
public:
    bool checkRow(int x, vector<vector<char>> &board) { // checking the row if all the elements are unique
        int i;
        map<char, int>mp;
        for(i = 0; i < 9; i++) {
            if(board[x][i] != '.') {
                if(mp[board[x][i]]) {
                    return false;
                } else {
                    mp[board[x][i]] = 1;
                }
            }
        }
        return true;
    }
    
    bool checkColumn(int y, vector<vector<char>>&board) {       // checking for column
        int i;
        map<char, int>mp;
        for(i = 0; i < 9; i++) {
            if(board[i][y] != '.') {
                if(mp[board[i][y]]) {
                    return false;
                } else {
                    mp[board[i][y]] = 1;
                }
            }
        }
        return true;
    }
    
    bool checkSquare(int x, int y, vector<vector<char>> &board) {//checking for the sqaure of 3 x 3
        int i, j;
        map<char, int>mp;
        
        for(i = x; i < x + 3; i++) {
            for(j = y; j < y + 3; j++) {
                if(board[i][j] != '.') {
                    if(mp[board[i][j]]) {
                        return false;
                    } else {
                        mp[board[i][j]] = 1;
                    }
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j;
        
        for(i = 0; i < 9; i++) {
            if(!checkRow(i, board) || !checkColumn(i, board))   // if there is any of row and column check fail
                return false;
        }
        
        for(i = 0; i < 9; i = i + 3) {
            for(j = 0; j < 9; j = j + 3) {
                if(!checkSquare(i, j, board))                   // if there is any failed case with the sqaure
                    return false;
            }
        }
        return true;
    }
};

/*
TC = O(n^3)
SC = O(1)
*/