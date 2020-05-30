#MayChallenge
/*
Link: https://leetcode.com/problems/remove-k-digits/

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

/*
TC = O()
SC = O()
*/

// Solution

class Solution {
public:
    string removeKdigits(string s, int k) {
        int len = s.size();
        if (len == k)
            return "0";
        
        stack<char>st;
        int i = 0;
        while(i < len) {
            while(!st.empty() && st.top() > s[i] &&  k) {
                st.pop();
                k--;
            }
            st.push(s[i]);
            i++;
        }
        
        while (k && !st.empty()) {
            st.pop();
            k--;
        }
        
        string ans = "";
        
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        i = 0;
        while (ans[i] == '0')
            i++;
        
        return i == ans.size() ? "0" : ans.substr(i);
    }
};