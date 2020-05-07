/*
Link: https://leetcode.com/problems/cousins-in-binary-tree/

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

Example 1:
Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
*/

// Solutiom
// Approach here is tot find the height and parent of the given number.
/*
TC = O(n) where n is the number of nodes.
SC = O(1)
*/

class Solution {
public:
    TreeNode * parentX = NULL, *parentY = NULL;         // pointer to store the parent of the given number
    int hX = -1, hY = -1;                               // height of x and y
    bool isCousins(TreeNode* root, int x, int y) {

        heightParent(root, x, y, 0, NULL);
        
        if (parentX != parentY && hX == hY)             // condition for cousin
            return true;
        return false;
    }
    
    void heightParent(TreeNode * root, int x, int y, int h, TreeNode *parent) {
        if (!root)
            return;
        
        if (root -> val == x) {                         // parent and height of x
            parentX = parent;
            hX = h;
        }
        
        if (root -> val == y) {                         // parent and height of y
            parentY = parent;
            hY = h;
        }
        
        heightParent(root -> left, x, y, h + 1, root);
        heightParent(root -> right, x, y, h + 1, root);
    }
};