/*
Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

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

// Solution 1 Using Recursion
/*
TC = O(n ^ 2)
SC = O(n ^ 2)   // recursion stack

*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size() || !inorder.size()) {
            return NULL;
        }
        int index = 0
        return constructTree(preorder, pos, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* constructTree(vector<int> &preorder, int index, vector<int> &inorder, int low, int high) {
        if (low > high) {
            return NULL;
        }

        int i;
        for (i = low; i <= high; i++) {                            // this can be improved by using map
            if (inorder[i] == preorder[index]) {                   // we store all the indexes of inorder and then find
                break;
            }
        }
        
        int index = i - low;
        
        TreeNode* root = new TreeNode(preorder[pos]);
        
        root -> left = constructTree(preorder, index, inorder, il, i - 1);
        root -> right = constructTree(preorder, index, inorder, i + 1, ih);
        
        return root;
    }
};


// Solution 2 
/*
TC = 
SC = 
*/