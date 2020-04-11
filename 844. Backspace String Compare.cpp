
Link: https://leetcode.com/problems/backspace-string-compare/

Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?

*/
// Solution 1
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        int i, j, n = S.size(), m = T.size();
        
        stack<char> st;
        
        for (i = 0; i < n; i++) {
            if (S[i] == '#') {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(S[i]);
            }
        }
        S = "";
        while (!st.empty()) {
            S += st.top();
            st.pop();
        }
        
        for (i = 0; i < m; i++) {
            if (T[i] == '#') {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(T[i]);
            }
        }
        
        T = "";
        while (!st.empty()) {
            T += st.top();
            st.pop();
        }
        
        if(S == T) {
            return true;
        }
        return false;
    }
};

/*
TC = O(n)
SC = O(n)
*/

// Solution 2

// We use two pointer approach here.
// We start from the back and if # is present at the index,
// then we find the next index which we si to be compared
// by counting the number of # and moving the pointer to
// left by same count.

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        int i = S.size() - 1, j = T.size() - 1, k;
        
        while (i >= 0 || j >= 0) {                  
            k = 0;
            while (i >= 0) {
                if (S[i] == '#') {
                    i--;
                    k++;
                } else if (k > 0) {
                    k--;
                    i--;
                } else {
                    break;
                }
            }
            
            k = 0;
            while(j >= 0) {
                if (T[j] == '#') {
                    j--;
                    k++;
                } else if (k > 0) {
                    k--;
                    j--;
                } else {
                    break;
                }
            }
            
            
            if (i < 0 && j < 0)
                return true;
            
            if (i < 0 || j < 0)
                return false;
            
            if (S[i] != T[j])
                return false;
            
            i--;
            j--;
        }
        return true;
    }
};
/*
TC = O(m + n)
SC = O(1)
*/