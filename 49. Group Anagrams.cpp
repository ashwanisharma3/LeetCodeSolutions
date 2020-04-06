/*
Link: https://leetcode.com/problems/group-anagrams/

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map <string, vector<string>> mp;                        // declaring map, where key is the sorted string, and vector contains
                                                                // the original strings.
        
        vector<vector<string>> ans;
        int i, n = strs.size();
        
        string s;
        
        for (i = 0; i < n; i++) {
            s = strs[i];                                        // copying current string to s,
            sort(s.begin(), s.end());                           // and sorting it
            mp[s].push_back(strs[i]);                           // stores the value with the key as the sorted string
        }
        
        map<string,vector<string>>::iterator it = mp.begin();
        
        while(it != mp.end()) {                                 // iterating till the end of the map
            ans.push_back(it->second);                          // inserting all the vectors containing anagram strings.
            it++;                                               // increasing iterators
        }
        return ans;
    }
};

/*
Time Complexity: O(n * k * log K)
Space Complexity: O(nk)                 where is the length of the longest string and n is the size of vector
*/
