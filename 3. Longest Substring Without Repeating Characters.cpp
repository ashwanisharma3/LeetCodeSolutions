/*
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

// Soltuion 1 : Using Map
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSoFar = 0, i, start = 0, currMax = 0, len = s.length();
        
        if (!len)
            return 0;

        map<char, int> mp;			// map to store the recent index of the char
        mp[s[0]] = 0;				// first char
        
        for (i = 1; i < len; i++) {
            if (mp.find(s[i]) != mp.end()) 
            {	// if the char is present
                if (mp[s[i]] == start) 		// if the string started from the last seen index of current char
                {	
                    start++;
                } 
                else if (mp[s[i]] > start) 	// if the starting of current substring is before the last seen index
                {
                    start = mp[s[i]] + 1;
                }
            }
            
            mp[s[i]] = i;			// storing the index of char
            currMax = max (currMax, i - start);
        }
        
        return currMax + 1;
    }
};

/*
TC = O(n)
SC = O(n)
*/

// Solution 2 : 

int lengthOfLongestSubstring(string s) {
	int maxSoFar = 0, i, start = 0, longString = 0, len = s.length();
	// maxSoFar saves the length of ongoing Substring
	// start saves the index when the current substring started
	// longString is the longest substring
	int lastSeen[256];			// stores the the recent position of the character

	std::fill_n(lastSeen, 256, -1);  	// initialize all elements to -1
	for (i = 0; i < len; i++) {
		if( lastSeen[s[i]] == -1 ) { 	// check if the element is seen for the first time and
			maxSoFar++;		// increases maxSoFar
			lastSeen[s[i]] = i;			
		} 
		else 
		{
		if(start == lastSeen[s[i]])	// if the current char and char at start of the string
		{				// same then,
			start++; 		// increase the start by 1
			lastSeen[s[i]] = i;	// and stores the lastSeen of current char.
		} 
		else if (start > lastSeen[s[i]])// if the start of the current substring is after the
		{				// lastSeen of the current char 
			lastSeen[s[i]] = i;	// just store the lastSeen
			maxSoFar++;		// and increase maxSoFar
		}
		else 							// if the start of the current substring is before lastSeen
		{							// of the current Char then,
			start = lastSeen[s[i]] + 1;			// start of the string will be next index of the lastSeen of current char
			longString = max (maxSoFar, longString); 
			maxSoFar = i - start + 1;			// maxSoFar is the length of substring from start to current
			lastSeen[s[i]] = i;
		}
		}
	} 
return max(longString, maxSoFar);
}
