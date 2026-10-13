/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, string path, vector<string>& result) {
        if (!root) return;
        
        path += to_string(root->val);
        
        // If it's a leaf node, add the accumulated path to the result
        if (!root->left && !root->right) {
            result.push_back(path);
            return;
        }
        
        // Continue DFS to child nodes
        if (root->left) dfs(root->left, path + "->", result);
        if (root->right) dfs(root->right, path + "->", result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
};