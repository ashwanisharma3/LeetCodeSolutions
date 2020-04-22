/*
Link: https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;                   // answer vector
        
        generateString(n, n, "", ans);
        return ans;
    }
       
    void generateString (int openB, int closeB, string s, vector<string> &ans) {    // openB denotes the number of open bracket yet to be inserted
                                                                                    // openB denotes the number of open bracket yet to be inserted
        if (!openB && !closeB) {              // if none of the open or close bracket left
            ans.push_back(s);
        }
        
        if (openB) {                          // if open brackets can be inserted
            generateString(openB - 1, closeB, s + '(', ans);
        }
        
        if (openB < closeB) {                 // right bracket can only be inserted when there are more open brackets
            generateString(openB, closeB - 1, s + ')', ans);
        }
    }
};