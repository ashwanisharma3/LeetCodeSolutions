/*
Link: https://leetcode.com/problems/longest-palindromic-substring/

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

string longestPalindrome(string s) {
        int i, len = s.length(), palin_length = 1, start = 0; // palin_length is the length of longest palindrome
                                                              // start saves the first index of the longest palidrome
                                                              
        int left, right, curr_len = 1;                        // curr_len is the length of the ongoing palindrome
        
        for (i = 0; i < len - 1 && palin_length < 2*(len-i); i++) 
        {
            if (s[i] == s[i+1])                               // checking for even length palindrome
            {                             
                left = i - 1;
                right = i + 2;
                curr_len = 2;
                
                while (left >= 0 && right < len) 
                {          
                    if (s[left] == s[right]) 
                    {
                        left--;
                        right++;
                        curr_len += 2;
                    } 
                    else 
                    {
                        break;
                    }
                }
                
                if (palin_length < curr_len) 
                {
                    palin_length = curr_len;
                    start = left + 1;
                }
            }
            if (i-1 >= 0 && s[i-1] == s[i+1])                  //checking for odd length palindrome
            {
                left = i - 2;
                right = i + 2;
                curr_len = 3;
                
                while (left >= 0 && right < len) 
                {
                    if (s[left] == s[right]) 
                    {
                        left--;
                        right++;
                        curr_len += 2;
                    } 
                    else 
                    {
                        break;
                    }
                }
                
                if (palin_length < curr_len) 
                {
                    palin_length = curr_len;
                    start = left + 1;
                }
            }
        }
        return s.substr(start, palin_length);
    }
    
    /*
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    */
