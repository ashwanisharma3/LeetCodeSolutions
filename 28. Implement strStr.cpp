/*
Link: https://leetcode.com/problems/implement-strstr/

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/

// Solution 1 - KMP Algorithm

class Solution {
public:
    void fillPattern (string needle, int pattern[]) {
        int i, j = 0, n = needle.size();
        
        pattern[0] = 0;

        for (i = 1; i < n; i++) {
            if(needle[i] == needle[j]) {
                pattern[i] = j + 1;
                j++;
            } else {
                while(j > 0 && needle[i] != needle[j]) {
                    j = pattern[j - 1];
                }
                if (needle[i] == needle[j]) {
                    pattern[i] = j + 1;
                    j++;
                } else {
                    pattern[i] = 0;
                }
            }
        }
    }
    
    int strStr(string haystack, string needle) {
        
        if (needle == "") {
            return 0;
        }

        int i, j = 0, n = needle.size(), m = haystack.size();
        
        if ((n > m)) {
            return -1;
        }
        
        int pattern[n];
        
        fillPattern (needle, pattern);

        for (i = 0; i < m; i++) {
            if (haystack[i] == needle[j]) {
                j++;
            } else {

                while(j > 0 && haystack[i] != needle[j]) {
                    j = pattern[j - 1];
                }

                if (haystack[i] == needle[j]) {
                    j++;
                }
            }
            
            if (j == n) {
                return i - n + 1;
            }
        }
        return -1;
    }
};

// Solution 2 - Iterative
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0, k = 0, m = haystack.length(), n = needle.length();
        if(!n)
            return 0;
        if(!m || m < n)
            return -1;
        
        while (i < m && j < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = 0;
                k++;
                i = k;
            }
            
            if (j == n)
                return i - n;
        }
        
    return -1;
    }
};

