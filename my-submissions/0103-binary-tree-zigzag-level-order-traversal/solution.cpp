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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> op;
        while (!q.empty()) {
            if (q.front() == NULL) {
                q.pop();
                result.push_back(op);
                if (q.empty())
                    break;
                op.clear();
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
        for(int i = 0;i<result.size();i++){
            if(i % 2 != 0){
                reverse(result[i].begin(),result[i].end());
            }
        }
        return result;
    }
};
