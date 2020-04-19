/*
Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

// Solution 1 Using Stack
/*
TC = O(n)
SC = O(n)
*/
// The approach is to reach the left most node of the tree and then right and then previous.
// We store the left child of the node in the stack and when the left node is null, then store 
// the value of the node and then move to right of the node and then traverse through the left
// children of it
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        
        stack<TreeNode *> st;                   
        
        TreeNode * current = root;
        
        while (current || !st.empty()) {        
            
            while (current) {
                st.push(current);
                current = current -> left;
            }
            
            current = st.top();
            st.pop();
            ans.push_back(current -> val);
            current = current -> right;
        }
        
        return ans;
    }
};

// Solution 2 Using Morris Algorithm - Without Stack and Recursion
// The algorithm uses the concept of threaded binary tree. In inorder traversal the right most node of
// left substree is predecessor of the root. Same concept is used here. We store the address of parent node
// in the right most node of the left subtree.
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        TreeNode* current = root;
        TreeNode * pre;
        
        while (current) {
            if (!current -> left) {                     // if left child deosn't exists
                ans.push_back(current -> val);          // save its value
                current = current -> right;             // and make current = right child
            } else {
                pre = current -> left;                  // if left child of current exists
                
                while (pre -> right) {                  // move the right most node of the left subtree
                    pre = pre -> right;
                }
                
                pre -> right = current;                 // storing the address of current in the right most node 
                                                        // of the left subtree
                
                TreeNode * temp = current;              // saving current
                current = current -> left;              // moving current to left of current
                temp -> left = NULL;                    // making the left of previous current NULL.
            }
        }
        
        return ans;
    }
};
