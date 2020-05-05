/*
Link: https://leetcode.com/problems/fraction-to-recurring-decimal/

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"
*/

// Solution
// Uses the approach of long division method.

/*
TC = O(n)
SC = O(n)
*/

class Solution {
public:
    string fractionToDecimal(long long int num, long long int den) {
        if(num == 0)
            return "0";
        map<int, int> mp;
        string ans = "";
        if ((num < 0) ^ (den < 0))
            ans.push_back('-');
        
        ans += to_string(abs(num / den));
        
        num = num % den;
        
        long long int deno = abs(den);
        long long int nume = abs(num);
        
        if (num == 0)
            return ans;
        
        ans += '.';
        
        while (nume != 0) {
            if (mp.find(nume) !=mp.end()) {
                ans.insert(mp[nume], "(");
                ans.push_back(')');
                break;
            }
            mp[nume] = ans.size();
            nume *= 10;
            ans += to_string(nume / deno);
            
            nume %= deno;
        }        
        return ans;
    }
};