/*
Link: https://leetcode.com/problems/sort-colors/

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/

/*
TC = O(n)
SC = O(1)
*/

// Approach is to bring all the zero to left side and twos to right side.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        
        int i = 0, j = len - 1, k = 0;          // i denote next to the last index where zero is present from start
                                                // j denotes the the last index where 2 is present from end
                                                // k is the traverse pointer
        
        while (k <= j) {                        // until the traverse pointer meet the 2's pointer   
            if (nums[k] == 2) {                 // if the number at k is equal to swap it to jth element i.e. next to the current series of 2's
                swap(nums[k], nums[j]);
                j--;
            } else if (nums[k] == 0) {          // swap it to the next of where last zero from start is there.
                swap(nums[k], nums[i]);
                i++;
                k++;
            } else {
                k++;
            }
        }
    }
};