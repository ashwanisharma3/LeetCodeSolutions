/*
Link: https://leetcode.com/problems/valid-palindrome/

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/

// Solution 1
class Solution {
public:
    bool isPalindrome(string s) {
        int i, j = s.size() - 1;
        
        i = 0;
        while(i < j) {
            while (i < j && !isalnum(s[i]))             // if the char at i is not alphanumeric
                i++;
            
            while (i < j && !isalnum(s[j]))             // if the char at j is not alphanumeric
                j--;
            
            if (tolower(s[i]) == tolower(s[j])) {       
                i++;
                j--;
            }
            else {                                      // if char at i & j are not equal
                return false;
            }
        }
        return true;
    }
};

/*
TC = O(n)
SC = O(1)
*/

=============================================================================================================================
// Solution 2

class Solution {
public:
    bool isPalindrome(string s) {
        int i, j, n = s.size();
        
        for(i = 0; i < n; i++) {
            s[i] = tolower(s[i]);                                       // converting to lower case
        }
        
        i = 0;
        j = n - 1;
        
        while(i < j) {
            if(s[i] >= '0' && s[i] <= '9' && s[j] >= '0' && s[j] <= '9') {
                if(s[i] == s[j]) {
                    i++;
                    j--;
                } else {
                    return false;
                }
            } else if(s[i] >= 'a' && s[i] <='z' && s[j] >= 'a' && s[j] <='z') {
                if(s[i] == s[j]) {
                        i++;
                        j--;
                    } else {
                        return false;
                    }
            } else if (((s[i] >= 'a' && s[i] <='z') && (s[j] >= '0' && s[j] <= '9')) || ((s[j] >= 'a' && s[j] <='z') && (s[i] >= '0' && s[i] <= '9'))){
                return false;
            } else {
                if((s[i] < 'a' || s[i] > 'z') && (s[i] < '0' || s[i] > '9'))
                    i++;
                if((s[j] < 'a' || s[j] > 'z') && (s[j] < '0' || s[j] > '9'))
                    j--;
            }
        }
        return true;
    }
};
