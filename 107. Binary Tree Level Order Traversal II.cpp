#JulyChallenge
/*
Link: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

// Solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, vector<int>> mp;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        levelOrder(root, 0);
        
        vector<vector<int>> ans;
        
        for(auto it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(it -> second);
        }
        
        return ans;
    }
    
    void levelOrder(TreeNode *root, int h) {
        if (root == NULL)
            return;
        
        mp[h].push_back(root -> val);
        
        levelOrder(root -> left, h - 1);
        levelOrder(root -> right, h - 1);
    }
};