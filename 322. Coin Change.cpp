/*
Link: https://leetcode.com/problems/coin-change/

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/
/*
TC = O(n^2)
SC = O(n)
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int i, j, len = coins.size();
        
        int dp[amount + 1];
        
        dp[0] = 0;
        
        for (i = 1; i < amount + 1; i++)
            dp[i] =INT_MAX;
        
        for (i = 1; i < amount + 1; i++) {
            for (j = 0; j < len; j++) {
                if (coins[j] <= i) {
                    int temp = dp[i - coins[j]];
                    if (temp != INT_MAX && temp + 1 < dp[i])
                        dp[i] = temp + 1;
                }
            }
        }
        if(dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};