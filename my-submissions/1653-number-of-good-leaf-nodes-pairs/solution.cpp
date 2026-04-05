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
    vector<int> dfs(TreeNode*& root, int& distance) {
        // base case
        if (root == NULL)
            return {}; // empty vector;

        vector<int> left = dfs(root->left, distance);
        vector<int> right = dfs(root->right, distance);

        // if the node is a leaf node then
        if (root->left == NULL && root->right == NULL) {
            return {1}; // one to the parent;
        }

        // main logic
        vector<int> c = right;
        for (auto &val : c) {
            val++;
        }
        for (int i = 0; i < left.size(); i++) {
            for (int j = 0; j < right.size(); j++) {
                if (left[i] + right[j] <= distance) {
                    result++;
                }
            }
            c.push_back(left[i] + 1);
        }
        return c;
    }
    int result = 0;
    int countPairs(TreeNode* root, int distance) {
        // edge case
        if (root == NULL)
            return 0;

        dfs(root, distance);
        return result;
    }
};
