/*
Link: https://leetcode.com/problems/task-scheduler/

Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

 

Example:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 

Constraints:

The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
*/

// Solution
// Approach here is that, doesn't matter what we will need to have n + 1 element at least before
// the tasks repeat themselves. 
// So we have two cases:
// 1. When CPU is never idle: In that case number of intervals will be equal to the number of processes
// 2. When idle(s) is/are used: In such case we find the most occurring task (x times) and we can observe that
//    until (x - 1) occurences of that task there should be n + 1 task for each occurence and after wards only 
//    we can schedule the last occurence of the task. Since it occured maximum number of times there would be 
//    no need of any other tasks scheduling after it thus only count the most occuring if more than one.

/*
TC = O(n)
SC = O(n)
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int>mp;
        
        for (char i : tasks) {
            mp[i]++;
        }
        int cnt = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            cnt = max(cnt, it -> second);
        }
        
        int ans = (cnt - 1) * (n + 1);
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it -> second == cnt)
                ans++;
        }
        return max(int(tasks.size()), ans);
    }
};