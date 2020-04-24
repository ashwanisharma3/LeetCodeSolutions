/*
Link: https://leetcode.com/problems/top-k-frequent-elements/

Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
*/

// Using priority queue

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       priority_queue<pair<int, int> > pq; 

        int i, len = nums.size();
        map<int, int> mp;
        for (i = 0; i < len; i++) {
            mp[nums[i]]++;
        }
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            pq.push(make_pair(it -> second, it -> first));
        }

        vector<int> ans;
        
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};