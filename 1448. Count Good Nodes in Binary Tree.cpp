#
/*
Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/

Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

 

Example 1:



Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
Example 2:



Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
Example 3:

Input: root = [1]
Output: 1
Explanation: Root is considered as good.
 

Constraints:

The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].
*/

// Solution

/*
TC = O(n)       where is n is the number of nodes.
SC = O(1)
*/

class Solution {
public:
    int cnt = 0;
    int goodNodes(TreeNode* root) {
        check(root, root -> val);
        return cnt;
    }
    
    void check(TreeNode *root, int max_so_far) {
        if (!root)
            return;
        if (root -> val >= max_so_far)
            cnt++;
        
        max_so_far = max(max_so_far, root -> val);
        
        check(root -> left, max_so_far);
        check(root -> right, max_so_far);
    }
    
};