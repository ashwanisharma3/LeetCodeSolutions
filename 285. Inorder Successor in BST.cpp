/*
Link: https://leetcode.com/problems/inorder-successor-in-bst
Link: https://www.lintcode.com/problem/inorder-successor-in-bst/description

Given a binary search tree (See Definition) and a node in it, find the in-order successor of that node in the BST.

If the given node has no in-order successor in the tree, return null.

*/
// Solution 1 : Iterative approach

// Approach is to save the last node where last left move was made as it saves the successor of the left subtree.
class Solution {
public:
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        
        TreeNode* ans = NULL;
        
        TreeNode* current = root;
        
        while(!current && current -> val != p -> val) { // while current is present and value of node is not equal to target
            if (current -> val > p -> val) {            // if the value of node is greater is than the target
                ans = current;                          // save this node, saving the successor of left sub tree.
                current = current -> left;              // move to left of the current
            } else {
                current = current -> right;             // searching for the element in right subtree
            }
        }
        
        if (current == NULL) {                          // the target node is not present in the tree
            return NULL;
        }
        
        if (current -> right == NULL) {                 // since right child doesn't exists
            return ans;                                 // ans is the node where last left move was made
        }
        
        current = current -> right;                     // if right child exists 
        while (current -> left) {                       // then, answer is the left most child of the right subtree.
            current = current -> left;
        }
        return current;
        
    }
};


// Solution 2 : Recursive Approach

class Solution {
public:
    TreeNode* ans = NULL;

    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        traversal(root, p);
        return ans;
    }
    
    void traversal (TreeNode * root, TreeNode * p) {
        
        if (!root) {
            return;
        }
        
        if (root -> val > p -> val) {           // saving the node where last left turn was taken and 
            ans = root;                         // 
            traversal(root -> left, p);
            return;
        } else {                                // when this is executed where, p -> val == root -> val, 
            traversal(root -> right, p);        // this will lead to the leftmost node of the right tree.
            return;                             
        }
        return;
    }
};
