/*
Link: https://leetcode.com/problems/fizz-buzz/

Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/
// Using sieve
class Solution {
public:
    int countPrimes(int n) {
        if(n < 2)
            return 0;
        int i, j, arr[n];
        
        for(i = 2; i < n; i++)
            arr[i] = 1;
        
        for(i = 2; i * i < n; i++) {
            if (arr[i]){
                for (j = i * i; j < n ; j = j + i)
                    arr[j] = 0;
            }
        }
        int ans = 0;
        for (i = 2; i < n; i++) {
            (arr[i] == 1) ? ans++ : 0;
        }
        return ans;
    }
};