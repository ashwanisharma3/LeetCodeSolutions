/*
Link: https://leetcode.com/problems/reverse-string/

Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i, n = s.size();
        
        for(i = 0; i < (n+1) / 2; i++) {
            swap(s[i], s[n-1-i]);               // using for loop
        }

        // while(i < n) {                       // using while
        //     swap(s[i++], s[n--]);
        // }

        // reverse(s.begin(), s.end());         // using reverse function in vector

    }
};

/*
TC = O(n)
SC = O(1)
*/