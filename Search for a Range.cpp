/*
Link: https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/802/

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

// Solution
// Approach is to use binary search and find the first and last index of the range.

/*
TC = O(log n)
SC = O(1)
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        
        int start = 0, end = len - 1, mid;
        vector<int> ans;
        
        while (start <= end) {
            mid = start + (end - start) / 2;
            
            if (nums[mid] == target) {                          
                if (mid - 1 < 0 || nums[mid - 1] < nums[mid]){  // checking if mid is the first element or previous element is less than target.
                    ans.push_back(mid);
                    break;
                } else {                                        // else bringing end pointer to mid
                    end = mid - 1;
                }
            } else if (nums[mid] < target) {                    // increase the start pointer
                start = mid + 1;
            } else {
                end = mid - 1;                                  // decrease the end pointer
            }
        }
        
        start = mid;                                            // since end can't be before start of the range
        end = len - 1;
        
        while (start <= end) {
            mid = start + (end - start) / 2;
            
            if (nums[mid] == target) {
                if (mid + 1 >= len || nums[mid + 1] > nums[mid]){
                    ans.push_back(mid);
                    break;
                } else {
                    start = mid + 1;
                }
            } else {
                end = mid - 1;
            }
        }
        if (!ans.size()){
            ans = {-1, -1};
        }
        return ans;
    }
};