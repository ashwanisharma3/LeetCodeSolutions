/*
Link: https://leetcode.com/problems/symmetric-tree/

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Follow up: Solve it both recursively and iteratively.

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

// Recursive Approach

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        if(!root)                                       // if root is null then tree is symmetric
            return true;
        
        return check(root -> right, root -> left);       
    }
    
    bool check(TreeNode* root1, TreeNode* root2) {      // given the left and right node we check
        
        if(!root1 && !root2) {                          // if both the nodes are null
            return true;
        }
        
        if(!root1 || !root2)                            // either any of the node is not null and other one is.
            return false;
        
        return root1 -> val == root2 -> val             // checking for equality of the value of the nodes
            and check(root1 -> right, root2 -> left)    // call checking for left and right of the subtree
            and check(root1 -> left, root2 -> right);
    }
};

/*
TC = O(n)   where n is the number of nodes
SC = O(n)
*/


// Iterative Approach
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        
        // Here we use queue to store the left and right of the node and then check their value

        queue<TreeNode *> q;
        
        q.push(root);                           // inserting root into the queue
        q.push(root);                           // we can insert the left and right node the root here as well
        
        while (!q.empty()) {
            
            TreeNode *a = q.front();            // accessing the front node of the queue
            q.pop();                            // poping out the first element

            TreeNode *b = q.front();            // same as above
            q.pop();
            
            if(a && b) {                        // if both the node exists
                if (a -> val != b -> val) {     // if the value of the nodes aren't equal
                    return false;
                }
                
                q.push(a -> right);             // first pushing right of a then left of b, and then vice-versa
                q.push(b -> left);
                q.push(a -> left);
                q.push(b -> right);
            } else if (!a && !b)                // if both the node null then we must continue untill the queue is empty
                continue;
            else {
                return false;                   // if any of the node is not null and other is null
            }
        }
        return true;
    }
};

/*
TC = O(n)   where n is the number of nodes
SC = O(n)
*/