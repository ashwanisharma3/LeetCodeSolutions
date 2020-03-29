/*
Link: https://leetcode.com/problems/median-of-two-sorted-arrays/

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        
        if (m == 0) {                                                   // if nums1 is empty, return the median of nums2
            if (n % 2) {                                           
                return nums2[n/2];
            }
            return (nums2[n/2] + nums2[n/2 - 1]) / 2.0;
        }
        if (n == 0) {                                                   // if nums2 is empty return the median of nums1
            if(m % 2) {
                return nums1[m/2];
            }
            return (nums1[m/2] + nums1[m/2 - 1]) / 2.0;
        }
        
        // using the approach that on the both the sides (i.e. right and left) of median
        // the number of elements must be equal.
        // We will try to divide both the array in such a way that number of elements on 
        // the left side of i & j and right side of i & j are equal,
        // and increase and decrease i and j in same proportion.
        
        int min_index = 0, max_index = m, i, j, median;                 // i: index for nums1,  j: index for nums2              
                                                                        // min_index and max_index is the range in nums1 where the
                                                                        // median can be found. Also, will be used to identify the 
                                                                        // number of elements on the left and right side
        while(min_index <= max_index) {
            
            i = (min_index + max_index) / 2;                            // divide nums1 in two parts
            j = (m + n + 1) / 2 - i;                                    // we find such a j that above condition is satisfied 
                                                                        // i.e. equal number of elements on both sides
            
            if (i > 0 && j < n && nums1[i-1] > nums2[j])                // checking if the highest element in left of nums1 is 
            {                                                           // greater than minimum in right of nums2.
                max_index--;                                            // we decrease max_index as we need to move i to left as 
            }                                                           // left of i has more greater number than the median.
            
            else if ( i < m && j > 0 && nums1[i] < nums2[j-1])          // checking if the highest element in left of nums2 is 
            {                                                           // greater than minimum in right of nums2.
                min_index++;
            } 
            else                                                        // we have reached the median
            {
                if (i == 0)                                             // i equals to zero means, there is not element on the left of nums1
                {                                                       // hence median is in nums2.
                    median = nums2[j - 1];
                } 
                else if (j == 0)                                        // same as above
                {
                    median = nums1[i - 1];
                } 
                else                                                 
                {
                    median = max (nums1[i-1], nums2[j-1]);              // setting median
                }
                break;
            }
        }
        if ((m + n) % 2)                                                // if total number of elements are odd
        {
            return median;
        }
        // if total number of elements are even
        if ( i == m)                                                    // if there is no element on the right of i in nums1
        {
            return (median + nums2[j]) / 2.0;                           // median is average of the two medians
        }
        
        if ( j == n)                                                    // if there is no element on the right of j in nums2
        {
            return (median + nums1[i]) / 2.0;
        }
        
        return (median + min (nums1[i], nums2[j])) / 2.0;               // average of the two medians.
    }
};
