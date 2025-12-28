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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> op;
        while (!q.empty()) {
            if (q.front() == NULL) {
                q.pop();
                result.push_back(op);
                op.clear();
                if (q.empty()) {
                    break;
                }
                q.push(NULL);
                continue;
            }
            TreeNode* temp = q.front();
            op.push_back(temp->val);
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
            q.pop();
        }
        return result;
    }
};
