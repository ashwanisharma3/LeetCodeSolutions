/*
Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example: 

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

// Solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // inorder traversal
        queue<TreeNode *> q;
        string ans;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode *temp = q.front();
                q.pop();
                if (temp){
                    ans += to_string(temp -> val) + ",";
                    q.push (temp -> left);
                    q.push (temp -> right);
                } else {
                    ans += "null," ;
                }
            }
        }
        ans.pop_back();
        cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // obtaining tree from inorder traversal
        queue<TreeNode *> q;
        vector<string> v;
        
        stringstream ss(data);
        
        while (ss.good()) {
            string substr;
            getline(ss, substr, ','); 
            v.push_back(substr); 
        }
        
        if (v[0] == "null")
            return NULL;
        
        TreeNode *root = new TreeNode(stoi(v[0]));
        q.push(root);
        int i = 1;
        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            
            if(temp) {
                temp -> left = v[i] == "null" ? NULL : new TreeNode(stoi(v[i]));
                i++;
                temp -> right = v[i] == "null" ? NULL : new TreeNode(stoi(v[i]));
                i++;
                q.push(temp ->left);
                q.push(temp ->right);
            }
        }
        
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));