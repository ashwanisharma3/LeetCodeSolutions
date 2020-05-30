#MayChallenge
/*
Link: https://leetcode.com/problems/course-schedule/

There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
*/


// Solution

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& preq) {
        int len = preq.size(), i;
        
        vector<int> inDegree(numCourses, 0);
        
        for(i = 0; i < len; i++)
            inDegree[preq[i][0]]++;
        
        queue<int>q;
        
        for(i = 0; i < numCourses; i++) {
            if(inDegree[i])
                continue;
            q.push(i);
        }
        
        int cnt = q.size();
        
        while(!q.empty()) {
            int temp = q.front();
            q.pop();
            
            for(i = 0; i < preq.size(); i++) {
                if (preq[i][1] == temp) {
                    inDegree[preq[i][0]]--;
                    
                    if(inDegree[preq[i][0]] == 0) {
                        cnt++;
                        q.push(preq[i][0]);
                    }
                }
            }
        }
        
        return cnt == numCourses;
        
    }
};