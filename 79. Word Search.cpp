/*
Link: https://leetcode.com/problems/word-search/

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/

class Solution {
public:
    int m, n;
    bool exist(vector<vector<char>>& board, string word) {
        
        m = board.size();
        
        // if (!m)
        //     return false;
        n = board[0].size();
        vector<vector<bool>> visited (m, vector<bool> (n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[0] == board[i][j]) {
                    if (check (board, word, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool check (vector<vector<char>> board, string word, int i, int j) {
        if (word.size() == 0) {
            return true;
        }
        
        if (i < 0 
            || j < 0 
            || i >= m 
            || j >= n  
            || word[0] != board[i][j]
           ) {
            return false;
        }
        
        char ch = board[i][j];
        board[i][j] = '#';
        string s = word.substr(1);
        
        if (check(board, s, i - 1, j) 
            || check(board, s, i + 1, j) 
            || check(board, s, i, j - 1) 
            || check(board, s, i, j + 1) 
            ) {
            return true;
        }
        // board[i][j] = ch;
        return false;
    }
};