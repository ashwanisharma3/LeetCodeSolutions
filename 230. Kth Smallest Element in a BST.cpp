/*
Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
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

// Solution 1: Using recursion and extra space O(n)
/*
TC = O(n)
SC = O(n)
*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inOrder(root, v);
        return v[k - 1];
    }
    
    void inOrder (TreeNode * root, vector<int> &v) {
        if (!root) {
            return;
        }
        
        inOrder (root -> left, v);
        v.push_back(root -> val);
        inOrder (root -> right, v);
    }
};

// Solution 2 : Using recursion and constant space
/*
TC = O(n)
SC = O(1)
*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        inOrder (root, k, ans);
        return ans;
    }
    
    void inOrder (TreeNode * root, int &k, int &ans) {
        if (!root) {
            return;
        }
                
        inOrder (root -> left, k, ans);

        if (--k == 0) {
            ans = root -> val;
            return;
        }

        inOrder (root -> right, k, ans);
    }
};

// Solution 3 : Using stack
/*
TC = O(n)
SC = O(n)
*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        
        TreeNode * current = root;
        while(current || !st.empty()) {
            while (current) {
                st.push(current);
                current = current -> left;
            }
            
            current = st.top();
            st. pop();
            
            if (--k == 0) {
                return current -> val;
            }
            
            current = current -> right;
        }
        return 0;
    }
};