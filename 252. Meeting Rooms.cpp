/*
Link: https://leetcode.com/problems/meeting-rooms
      https://www.lintcode.com/problem/meeting-rooms-ii/description

Description
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example
Example1

Input: intervals = [(0,30),(5,10),(15,20)]
Output: 2
Explanation:
We need two meeting rooms
room1: (0,30)
room2: (5,10),(15,20)
Example2

Input: intervals = [(2,7)]
Output: 1
Explanation: 
Only need one meeting room

*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    static bool compareInterval(Interval i1, Interval i2) 
    { 
        return (i1.start < i2.start); 
    };
    
    int minMeetingRooms(vector<Interval> &v) {
        int len = v.size(), i;
        
        if (!len)
            return 0;
        
        sort(v.begin(), v.end(), compareInterval);              // sorting w.r.t start time
        
        priority_queue<int, vector<int>, greater<int>> pq;      // min priority queue 

        int ans = 0;
        for (i = 0; i < len; i++) {
            if (pq.empty()) {                                   // if empty
                pq.push(v[i].end);
            } else {
                while(!pq.empty() && pq.top() <= v[i].start)    // if there are classes which have ended before the current
                    pq.pop();
                pq.push(v[i].end);
            }
            
            ans = (pq.size() > ans) ? pq.size() : ans;          // answer is the maximum size of queue used.
        }
        
        return ans;
    }
};