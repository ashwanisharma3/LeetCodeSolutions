/*
Link: https://leetcode.com/problems/merge-sorted-array/

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/

class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int i = 0, j, len = m;
        
        for (i = 0; i < n; i++) {
            j = len - 1;
            while(j >= 0 && a[j] > b[i]){
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = b[i];
            len++;
        }
    }
};

/*
TC = O(n ^ 2)
SC = O(1)
*/