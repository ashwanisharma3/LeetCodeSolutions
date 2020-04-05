/*
Link: https://leetcode.com/problems/remove-element/
Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example 1:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,1,2,2,3,0,4,2], val = 2,

Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.

Note that the order of those five elements can be arbitrary.

It doesn't matter what values are set beyond the returned length.

*/

//using vector stls
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i;
        for (i = 0; i < nums.size();) {                 // we need check the size of vector every time as with the removal of element size will decrease.
            if(nums[i] == val) {
               nums.erase(nums.begin() + i);            // using erase to remove element
            }
            else
                i++;
        }
        return nums.size();
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

// using two pointer approach
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j, n = nums.size();
        for (j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {               
                nums[i] = nums[j];              // copying the elements other than val into their places
                i++;                            // i will not be increased if value of element is equal to val hence keeping i at the same place.
            }
        }
        return i;                               // the size of vector is still same as it was but all the elements after i length are equal to val.
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
