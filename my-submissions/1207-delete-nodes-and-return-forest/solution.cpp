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
    vector<TreeNode*> result;
    void dfs(TreeNode*& curr, set<int>& st) {
        if (curr == NULL)
            return;
        dfs(curr->left, st);
        dfs(curr->right, st);
        if (st.find(curr->val) != st.end()) {
            // we need to delete this element;
            if (curr->left != NULL) {
                result.push_back(curr->left);
            }
            if (curr->right != NULL) {
                result.push_back(curr->right);
            }
            curr = NULL;
            return;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // edge case
        if (!root)
            return result;

        set<int> st(to_delete.begin(),
                    to_delete.end()); // conver vector to set;

        // traverse the tree
        dfs(root, st);
        if (root != NULL) {
            result.push_back(root);
        }
        return result;
    }
};
