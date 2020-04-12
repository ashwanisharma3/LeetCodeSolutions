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
        int i = 0, j, len = m;              // i - index for b; j - index for a
        
        while (i < n) {                     // traversing array b from left
            j = len - 1;                    // traversing array a from the index where last element is present
            while(j >= 0 && a[j] > b[i]){   // until smaller is found
                a[j + 1] = a[j];            // copying current to next index
                j--;
            }
            a[j + 1] = b[i];                // saving the element from b to a at index i
            len++;
            i++;
        }
    }
};

/*
TC = O(n ^ 2)
SC = O(1)
*/