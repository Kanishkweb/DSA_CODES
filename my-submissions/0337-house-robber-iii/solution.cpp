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
    pair<int,int> solve(TreeNode* root){  // {withRoot,withoutRoot}
        // base case 
        if(root == nullptr) return {0,0};

        auto leftPair = solve(root->left);
        auto rightPair = solve(root->right);

        int withRoot = root->val + leftPair.second + rightPair.second;
        int withoutRoot = max(leftPair.first,leftPair.second) + max(rightPair.first,rightPair.second);

        return {withRoot,withoutRoot};
    }
    int rob(TreeNode* root) {
        auto ans =  solve(root);
        return max(ans.first,ans.second);
    }
};
