/*
Link: https://leetcode.com/problems/move-zeroes/

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/
// The apraoch here is to move all the zeroes to the end.
class Solution {
public:    
    void moveZeroes(vector<int>& nums) {
        
        int i = 0, j = 0 , n = nums.size();		// let i be called first pointer and j be second
        
        while(i < n && nums[i] != 0)        		// finding the first occurence of zero
            i++;
        
        j = i;						// saving the first zero index in j
        
        while(i < n) {
            if(nums[i] == 0) {				// if the element is zero we move first pointer to next position
                i++;
            } else {
                swap(nums[i], nums[j]);			// swap the number to the j index element 
                i++;					// and increase both of the index
                j++;
            }
        }
    }
};

/*
TC = O(n)
SC = O(1)
*/
