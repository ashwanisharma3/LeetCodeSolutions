/*
Link:

Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

 

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Note: 

1 <= preorder.length <= 100
The values of preorder are distinct.
*/

//Solution 1 : Recursively
/*
TC = O(n^2)
SC = O(n^2)             Recursion stack
*/

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return constructTree(preorder, 0, preorder.size() - 1);
    }
    
    
    TreeNode *constructTree(vector<int> preorder, int low, int high) {
        if (low > high) {
            return NULL;
        }
        int i = low;
        TreeNode *root = new TreeNode(preorder[i]);
        for (; i <= high; i++) {
            if (preorder[low] < preorder[i]) {
                break;
            }
        }
        
        root -> left = constructTree(preorder, low + 1,  i - 1);
        root -> right = constructTree(preorder, i, high);
        
        return root;
    }
};


// 