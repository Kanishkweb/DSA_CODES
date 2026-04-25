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
    TreeNode* NP = NULL;
    void solve(TreeNode *& root){
        // base case 
        if(root == NULL) return;

        solve(root->right);
        solve(root->left);
        // not the main element is root
        root->left = NULL;
        root->right = NP;
        NP = root;
    }

    void flatten(TreeNode* root) {
        solve(root);
    }
};
