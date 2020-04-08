/*
Link: https://leetcode.com/problems/contains-duplicate/

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int i, n = nums.size();
        
        map<int, int> myMap;                    // using map to store the presence of the numbers
        
        for(i = 0; i < n; i++) {
            if(myMap[nums[i]])                  // if the current number is already in map
                return true;                    // return true
                
            myMap[nums[i]] = 1;                 // else store the number, 1 as key value in map
        }
        return false;                           // if control reaches here implies all the elements occured only once in the vector
    }
};

/*
TC = O(n)
SC = O(n)
*/
