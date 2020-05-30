#MayChallenge
/*
Link: https://leetcode.com/problems/sort-characters-by-frequency/

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/


// Solution

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        
        for(char i : s) {
            mp[i]++;
        }
        
        priority_queue<pair<int, char>> pq; 
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            pq.push(make_pair(it -> second, it -> first));
        }
        
        string ans;
        
        while(!pq.empty()) {
            int x = pq.top().first;
            char y = pq.top().second;
            while (x--) {
                ans += y;
            }
            pq.pop();
        }
        return ans;
    }
};