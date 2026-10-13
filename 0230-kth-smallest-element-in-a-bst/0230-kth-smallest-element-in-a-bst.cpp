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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            // Push all left nodes to the stack
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // Process the current node
            curr = st.top();
            st.pop();
            k--;
            if (k == 0) {
                return curr->val;
            }

            // Move to the right subtree
            curr = curr->right;
        }

        return -1;
    }
};