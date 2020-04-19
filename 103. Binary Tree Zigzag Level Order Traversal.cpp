/*
Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<vector>
class Solution {
public:
    map<int, vector<int>> mp;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        mp.clear();
        int flag = 0;
        levelOrder (root, 0);
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vector<int> temp = it -> second;

            if(flag) {
                reverse(temp.begin(), temp.end());
                flag = 0;
            } else {
                flag = 1;
            }
            
            ans.push_back(temp);
        }
        return ans;
    }
    
    void levelOrder(TreeNode* root, int height) {
        if (!root) {
            return;
        }
        
        mp[height].push_back(root->val);
        
        levelOrder (root -> left, height + 1);
        levelOrder (root -> right, height + 1);
    }
};