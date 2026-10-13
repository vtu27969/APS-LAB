class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        
        // Check if it's a leaf node
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }
        
        // Recurse down the left and right subtrees with updated targetSum
        int remainingSum = targetSum - root->val;
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};