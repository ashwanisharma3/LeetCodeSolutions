/*
Link: https://leetcode.com/problems/diameter-of-binary-tree/

Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
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
class Solution {
public:
    int height = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        
        if (!root) {
            return 0;
        }
        
        int heightLeft = heightOfTree (root -> left);
        int heightRight = heightOfTree (root -> right);
        
        height = heightLeft + heightRight;
        
        int diameterLeft = diameterOfBinaryTree(root -> left);
        int diameterRight = diameterOfBinaryTree(root -> right);
        
        return max(heightLeft + heightRight, max(diameterLeft, diameterRight));
        
    }
    
    int heightOfTree (TreeNode *root) {                         // height of the tree
        if(!root) {
            return 0;
        }
        
        return 1 + max(heightOfTree(root -> left), heightOfTree(root -> right));
    }
};

/*
TC = O(n ^ 2)
SC = O(n ^ 2)
*/