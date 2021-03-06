/*
Link: https://leetcode.com/problems/valid-anagram/

Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

*/

// Solution 1 - using sorting
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());       // sorting s
        sort(t.begin(), t.end());       // sorting t
        if(s == t)                      // comparing them
            return true;
        return false;   
    }
};

/*
TC = O(n log n)
SC = O(1)
*/


// Solution 2

class Solution {
public:
    bool isAnagram(string s, string t) {
        int i, n = s.size(), m = t.size();
        
        if (n != m) {
            return false;
        }
        
        map<int, int>mp;
        
        for (i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        
        for (i = 0; i < m; i++) {
            if (!mp[t[i]]){
                return false;
            } else {
                mp[t[i]]--;
            }    
        }
        return true;
    }
};

/*
TC = O(n)
SC = O(1)       space complexity is constant as the input if english alphabet hence.
*/
/*
Follow Up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
- We can use map for that purpose
*/