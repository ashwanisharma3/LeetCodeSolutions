/*
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.
*/
// using two pointers

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j = 0, n = nums.size();
        if(!n) {                                // if nums is empty
            return 0;
        }
        
        for(i = 0; i < n - 1; i++) {
            if(nums[i] != nums[i+1]) {          // if two adjacent elements are different
                j++;                            
                nums[j] = nums[i+1];            // saving the i + 1 element to j
            }
        }
        return j+1;                             // returning j + 1 as j is indicating the index value. Hence, length of array j + 1
    }
};

/*
TC = O(n)
SC = O(1)
*/
