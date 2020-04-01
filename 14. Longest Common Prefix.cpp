/*
Link: https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.

*/

// Brute Force Solution
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (!strs.size()) {
            return "";
        }
        int i, j, ans=0, flag;
        char temp;
        for (i = 0; i < strs[0].size(); i++) {
            temp = strs[0][i];
            flag = 0;
            for (j = 1; j < strs.size(); j++) {
                if (strs[j].size() == ans) {
                    return strs[0].substr(0,ans);
                }
                if (strs[j][i] != temp) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                return strs[0].substr(0,ans);
            } else {
                ans++;
            }
        }
        return strs[0].substr(0,ans);
    }
};

/*
Time Complexity = O(n^2)
Space Complexity = O(1)
*/

// Trie Solution

