#contest
/*
Link: https://leetcode.com/problems/consecutive-characters/

Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character.

Return the power of the string.

 

Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
Example 3:

Input: s = "triplepillooooow"
Output: 5
Example 4:

Input: s = "hooraaaaaaaaaaay"
Output: 11
Example 5:

Input: s = "tourist"
Output: 1
 

Constraints:

1 <= s.length <= 500
s contains only lowercase English letters.
*/

// Solution

/*
TC = O(n)
SC = O(1)
*/

class Solution {
public:
    int maxPower(string s) {
        int len = s.size(), i;
        
        if(len == 0)
            return 0;

        int ans = 1, cur_max = 1;
        char cand = s[0];
        
        for (i = 1; i < len; i++) {
            if (cand == s[i]) {
                cur_max ++;
                continue;
            }

            cand = s[i];
            cur_max = 1;
            ans = max(ans, cur_max);
        }
        return ans;
    }
};