/*
Link: https://leetcode.com/problems/validate-binary-search-tree/
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
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
// Recursive Solution
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root, INT_MIN, INT_MAX);
    }
    
    bool check(TreeNode* root, long long int mn, long long int mx){
        if(!root)                                                   // if root is null
            return true;
        if(root->val < mn || root->val > mx)                        // if the BST constraint is not followed
            return false;
        long long int t1 = root->val, t2 = root->val;
        return check(root->left, mn, t1-1) 
            && check(root->right, t2+1, mx); // checking for left and right child
    }
};

// Recursive Solution with only TreeNode as parameter
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        isValid (root, NULL, NULL);
    }
    
    bool isValid (TreeNode * root, TreeNode * lower, TreeNode * upper) {
        if (!root) 
            return true;
        
        if (lower && lower -> val >= root -> val)
            return false;
        
        if (upper && upper -> val <= root -> val)
            return false;
        
        return isValid (root -> left, lower, root) 
            && isValid (root -> right, root, upper);
    }
    
};