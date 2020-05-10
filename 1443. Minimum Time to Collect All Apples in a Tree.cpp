#tree #DFS
/*
Link: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend in order to collect all apples in the tree starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [fromi, toi] means that exists an edge connecting the vertices fromi and toi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple, otherwise, it does not have any apple.

 

Example 1:



Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
Output: 8 
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
Example 2:



Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
Output: 6
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
Example 3:

Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
Output: 0
 

Constraints:

1 <= n <= 10^5
edges.length == n-1
edges[i].length == 2
0 <= fromi, toi <= n-1
fromi < toi
hasApple.length == n
*/

// Solution
// Approach here to go from bottom to top. We see if the node is an apple and if it is, then go back to
// to the root node (which is zero here) by going to its parent and to it parent and so on, ans add 2 to 
// the ans with every up node. We need to keep the track of the node already visited and stop going up
// if the parent is already visited.
/*
TC = O(n)
SC = O(n)
*/

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int i, lenE = edges.size(), lenA = hasApple.size();
        
        map<int, int> mp;

        for (i = 0; i < lenE; i++) {
            mp[edges[i][1]] = edges[i][0];              // storing parents of the edges
        }
        vector<bool>visited (lenA, false);
        
        int ans = 0;
        for (i = 1; i < lenA; i++) {
            if (hasApple[i]) {
                visited[i] = true;
                int x = mp[i];
                while (!visited[x] && x != 0) {         // when the node is neither visited not the root i.e. 0
                    ans += 2;
                    visited[x] = true;
                    x = mp[x];                          // look for the parent of current parent
                }
                ans+=2;
            }
        }
        return ans;
    }
};