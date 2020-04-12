/*
Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
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

// Iterative Solution:
// uses queue to traverse through the tree whicle storing the height of the node.
class Solution {
public:
    struct data {                                       // data structure for queue 
      TreeNode* node;                                   // to store the node and
      int h;                                            // its height

      data (TreeNode* i, int j) : node(i), h(j) {}      // function of saving the value
    } ;

    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int, vector<int>> mp;                       // map for storing the nodes at the height as key
        
        vector<vector<int>> ans;                        // vector for final answer
        
        queue<data> q;                                  // queue with data as the data type
        
        q.push(data(root, 0));                          // inserting first node of the tree i.e. root and height as zero
        
        while(!q.empty()) {                             // while is not empty
            data temp = q.front();                      // fetching the first of the queue
            
            if (temp.node) {                            // if node in the front is not null
                q.push(data(temp.node -> left, temp.h + 1));    // inserting the left node and its height
                q.push(data(temp.node -> right, temp.h + 1));   // inserting the right node and its height
                
                mp[temp.h].push_back(temp.node -> val);         // inserting the value of node at the height as key
            }
            
            q.pop();                                    // poping out the front
        }
        
        for (auto it = mp.begin(); it != mp.end(); it++) {      // itrating through map for final answer
            ans.push_back(it -> second);
        }
        return ans;
    }
};
/*
TC = O(n)
SC = O(n)
*/

// Recursive Solution
class Solution {
public:
    map<int, vector<int>> mp;                           // map for storing the nodes at the height as key

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;                        // vector for final answer
        
        findLevelOrder (root, 0);                       // calling function
        
        for (auto it = mp.begin(); it != mp.end(); it++) {      // itrating through map for final answer
            ans.push_back(it -> second);
        }
        
        return ans;
    }
    
    void findLevelOrder (TreeNode* root, int height) {
        if(!root)                                       // if root is null
            return;
        mp[height].push_back(root -> val);              // inserting value of root at height as key
        findLevelOrder (root -> left, height + 1);      // recursion on left child
        findLevelOrder (root -> right, height + 1);     // recursion on right child
    }
};

/*
TC = O(n ^ 2)
SC = O(n ^ 2)
*/