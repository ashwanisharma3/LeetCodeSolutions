/*
Link: https://leetcode.com/problems/increasing-triplet-subsequence/

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:

Input: [1,2,3,4,5]
Output: true
Example 2:

Input: [5,4,3,2,1]
Output: false
*/

/*
TC = O(n)
SC = O(1)
*/

// Approach here to find the number greater than mini and maxi
// where maxi is greater than mini but occured after mini
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        if(len < 3) {
            return false;
        }
        int mini = INT_MAX;
        int maxi = mini;
        for (int i = 0; i < len; i++) {
            
            if (nums[i] < mini) {
                mini = nums[i];
            }
            if (nums[i] > mini) {
                maxi = min(nums[i], maxi);
            }
            if(nums[i] > maxi)
                return true;

        }
        return false;
    }
};