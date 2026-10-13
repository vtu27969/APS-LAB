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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, trees are identical up to this point
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // If one node is null and the other isn't, trees are not identical
        if (p == nullptr || q == nullptr) {
            return false;
        }
        
        // If values don't match, trees are not identical
        if (p->val != q->val) {
            return false;
        }
        
        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};