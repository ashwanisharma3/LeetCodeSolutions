/*
Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return ArrayToBST(nums, 0, nums.size() - 1);
    }
    
    TreeNode * ArrayToBST(vector<int> &v, int start, int end) {
        if (start > end)
            return NULL;
        if (start == end) {
            return new TreeNode(v[start]);
        }
        
        int mid = ceil((start + end) / 2.0);
        // cout<<mid<<endl;
        TreeNode *node = new TreeNode(v[mid]);
        
        node -> left = ArrayToBST (v, start, mid - 1);
        node -> right = ArrayToBST (v, mid + 1, end);
        
        return node;
    }  
};
/*
TC = O(n ^ 2)
SC = O(n ^ 2)
*/

// Iterative Solution

// Approach is to save in stack the node in which the value is to be inserted, and the low and high,
// by which we will calculate the mid and that will be the value inserted 
class Solution {
public:
    struct info {                                   // structure to store information in stack
        int low;
        int high;
        TreeNode *node;
        info(int x, int y, TreeNode* p) : low(x), high(y), node(p) {};
    };
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid;
        
        if (high < 0) {                             // if there is no element in the vector
            return NULL;
        }
        
        stack<info> s;
        
        TreeNode* root = new TreeNode(0);           // root of the tree
        
        s.push(info(0, high, root));
        
        while (!s.empty()) {
            
            info temp = s.top();
            
            low = temp.low;
            high = temp.high;
            TreeNode *node = temp.node;
            
            s.pop();
            
            mid = low + ceil((high - low) / 2.0);
            
            node -> val = nums[mid];
            
            if (low < mid) {
                node -> left = new TreeNode(0);
                s.push(info(low, mid - 1, node -> left));
            }
            
            if(mid < high) {
                node -> right = new TreeNode(0);
                s.push(info(mid + 1, high, node -> right));
            }
        }
        
        return root;

    }
};