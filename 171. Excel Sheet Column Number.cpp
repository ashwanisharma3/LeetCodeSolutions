/*
Link: https://leetcode.com/problems/excel-sheet-column-number/

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
*/

// Solution


/*
TC = O(n)
SC = O(1)
*/

class Solution {
public:
    int titleToNumber(string s) {
        int i, j, len = s.size();
        int k = 0, ans = 0;
        char ch;
        while (s.size()) {
            ch = s[s.size() - 1];
            ans += pow (26, k) * int(ch -'A' + 1);
            k++;
            s.pop_back();
        }
        return ans;
    }
};