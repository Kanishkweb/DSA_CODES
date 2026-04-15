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
    int maxDep = INT_MIN;
    void dfs(TreeNode* root, int depth) {
        if (root == NULL)
            return;

        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
        maxDep = max(maxDep, depth);
    }
    int maxDepth(TreeNode* root) {
        // edge case
        if(root == NULL) return 0;
        dfs(root, 0);
        return maxDep+1;
    }
};
