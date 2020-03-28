/* 
Link: https://leetcode.com/problems/zigzag-conversion/

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

class Solution {
public:
    string convert(string s, int numRows) {
        int i = 0, j = 0, len = s.length();
        if (numRows == 1 || numRows >= len)                 // return the same string
            return s;
        
        vector<string> v(numRows);                          // vector of strings
        int flag=1;                                         // flag to keep a track if the row index to be increased or decreased
        
        while (i < len) {
            v[j].push_back(s[i]);
            if (flag) {
                j++;
            } else {
                j--;
            }
            if(j == 0 || j == numRows - 1) {                // switching flag when first or the last row is reached.
                flag = !flag;
            }
            i++;
        }
        string ans;
        for (i = 0; i < numRows; i++) {
            ans += v[i];
        }
        return ans;
    }
};


/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
