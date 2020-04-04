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
    vector<string> ans;                                 // global vector for final answer.
    vector<string> generateParenthesis(int n) {
        string s;
        generateString(n, n, s);
        return ans;
    }
    
    void generateString(int open, int close, string s) {// open is number of OPEN parenthesis, left to be inserted in the string s.
                                                        // close is number of CLOSE parenthesis, left to be inserted in the string s.
        if(!close) {                                    // if there is no more CLOSE parenthesis left, 
            ans.push_back(s);                           // end the string and push into the ans vector.
            return;
        }
        
        if(open) {                                      // if there exists OPEN parenthesis to be inserted
            generateString(open - 1, close, s +'(');    // adding '(' to the string, decreasing OPEN by 1
        }
        
        if(close > open) {                              // number of CLOSE parenthesis left can't be less than OPEN
            generateString(open, close - 1, s +')');    // // adding ')' to the string, decreasing CLOSE by 1
        }
    }
};
