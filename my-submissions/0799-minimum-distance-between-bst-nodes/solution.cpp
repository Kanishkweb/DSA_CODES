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
    int minDiffInBST(TreeNode* root) {
        // if(root == nullptr) return 0;
        traverse(root);
        int ans = INT_MAX;
        for(int i = 1;i<arr.size();i++){
            ans = min(ans,arr[i]-arr[i-1]);
        }   
        return ans;
    }
};
