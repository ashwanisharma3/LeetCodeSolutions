/*
Link: https://leetcode.com/problems/pascals-triangle/

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        if (numRows == 0) {
            return ans;
        }
        
        vector<int>v;                                   // sub vector
        v.push_back(1);                                 // first row
        
        ans.push_back(v);                               // inserting sub vector in ans
        
        if (numRows == 1) {
            return ans;
        }
        
        v.push_back(1);
        ans.push_back(v);
        int i, j;
        for (i = 1; i < numRows - 1; i++) {
            v.clear();
            v.push_back(1);
            for(j = 1; j < ans[i].size(); j++) {
                v.push_back(ans[i][j-1] + ans[i][j]);   // creating the next subsequent row
            }
            v.push_back(1);
            ans.push_back(v);
        }
        
        return ans;
    }
};

/*
TC = O(n ^ 2)
SC = O(n ^ 2)
*/