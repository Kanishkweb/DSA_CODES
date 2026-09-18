/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, int val) {
        if (root == nullptr)
            return;

        if (root->val < val) {
            // it will go to right
            if (root->right == nullptr) {
                root->right = new TreeNode(val);
                return;
            }
            traverse(root->right, val);
        } else {
            // it will go to left;
            if (root->left == nullptr) {
                root->left = new TreeNode(val);
                return;
            }
            traverse(root->left, val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
            return new TreeNode(val);
        traverse(root, val);
        return root;
    }
};
