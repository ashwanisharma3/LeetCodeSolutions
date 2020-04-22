/*
Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
public:
    map<char, string> mp = {                    // decalring map as per the key and the letters present on it.
        {'2',"abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string> ans;                         // vector for answer
    vector<string> letterCombinations(string digits) {
        if (!digits.size())
            return ans;
        
        makeString ("", digits);

        return ans;
    }
    
    void makeString (string s, string digits) {
        if (!digits.size())                                     // if there no digit left
            ans.push_back(s);                                   // we have our string
        else {
            string temp = mp[digits[0]];                        // letters with respect to the number
            
            for (int i = 0; i < temp.size(); i++) {             // for every character in the temp string
                makeString(s + temp[i], digits.substr(1));
            }
        }
    }
};