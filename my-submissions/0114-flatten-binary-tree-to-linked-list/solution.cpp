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
    void flatten(TreeNode* root) {
        // preorder reverse traversal // right // left // root;
        if(root == NULL) return; 
        flatten(root->right);
        flatten(root->left);
        root->left = NULL;
        root->right = NP;
        NP = root;
    }
};
