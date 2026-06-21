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
    int maxAns = INT_MIN;
    int dfs(TreeNode* root){
        // base case
        if(root == nullptr) return 0;

        int left = max(0,dfs(root->left));
        int right = max(0,dfs(root->right));
        int koi_ek_aacha = max(left,right) + root->val;
        int dono_path_aacha = left + right + root->val;
        int only_root_aacha = root->val;
        maxAns = max(maxAns,max(koi_ek_aacha,max(dono_path_aacha,only_root_aacha)));
        return max(koi_ek_aacha,only_root_aacha);
    }
    int maxPathSum(TreeNode* root) {
         dfs(root);
         return maxAns;
    }
};
