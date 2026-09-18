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
    vector<int>arr;
    void traverse(TreeNode* root){
        if(root == nullptr) return;

        traverse(root->left);
        arr.push_back(root->val);
        traverse(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        traverse(root);
        int n = arr.size();
        return arr[k-1];
    }
};
