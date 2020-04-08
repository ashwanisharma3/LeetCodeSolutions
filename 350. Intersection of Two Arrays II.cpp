/*
Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/

Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        int i, n = nums1.size();
        map<int, int> myMap;
        for(i = 0; i < n; i++) {
            myMap[nums1[i]]++;
        }
        n = nums2.size();
        
        for(i = 0; i < n ; i++) {
            if(myMap[nums2[i]]) {
                ans.push_back(nums2[i]);
                myMap[nums2[i]]--;
            }
        }
        return ans;
    }
};

/*
TC = O(n)
SC = O(n)
*/

========================================================================================================================================

/*
Follow Up:
What if the given array is already sorted? How would you optimize your algorithm?
- Use two pointers and solve in only one loop.

What if nums1's size is small compared to nums2's size? Which algorithm is better?
- If sorted can use the previous one and the above given solution as well.

What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
- Store the elements of nums1 in map and then call the limited elements of nums2 for further stuffs.
- If both the array can't be stored then sort then and use the approach given in first answer of the follow-up.
*/
