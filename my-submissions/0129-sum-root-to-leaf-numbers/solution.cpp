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
    void helper(TreeNode* root, string str,int &sum) {
        if (root == NULL)
            return;
        // if condition for leaf node;
        str += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            sum += stoi(str);
        }
        helper(root->left, str,sum);
        helper(root->right,str,sum);
    }
    int sumNumbers(TreeNode* root) {
        string str = "";
        int sum = 0;
        helper(root, str,sum);
        return sum;
    }
};
