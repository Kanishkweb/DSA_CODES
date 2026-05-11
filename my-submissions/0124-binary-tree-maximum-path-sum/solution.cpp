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
    int maxSum = INT_MIN;
    int solve(TreeNode* root){
      if(root == NULL) return 0;

      int l = solve(root->left);
      int r = solve(root->right);

      int koi_ek_accha = max(l,r) + root->val;
      int dono_path_accha = l + r + root->val;
      int only_root_aacha = root->val;
      maxSum = max(maxSum,max(dono_path_accha,max(koi_ek_accha,only_root_aacha)));  

      return max(koi_ek_accha,only_root_aacha);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};
