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
    void helper(TreeNode* root, TreeNode*& prev, int& ans) {
        if (root == NULL)
            return;
        helper(root->left, prev, ans);
        if (root != NULL && prev != NULL) {

            ans = min(ans, abs(root->val - prev->val));
        }
        prev = root;
        helper(root->right, prev, ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode* prev = NULL;
        helper(root, prev, ans);
        return ans;
    }
};
