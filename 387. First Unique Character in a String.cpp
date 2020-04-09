/*
Link: https://leetcode.com/problems/first-unique-character-in-a-string/

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.

*/

class Solution {
public:
    int firstUniqChar(string s) {
        int i, n = s.size();
        
        map<char, int> mp;              // declaring map
        
        for(i = 0; i < n ; i++) {
            mp[s[i]]++;                 // counting the number of occurences of a character
        }
        
        for(i = 0; i < n; i++) {
            if(mp[s[i]] == 1)           // if there exists some character which occured only ones.
                return i;
        }
        return -1;                      // if flow reaches here means that there was no character which was unique
    }
};

/*
TC = O(n)
SC = O(n)
*/