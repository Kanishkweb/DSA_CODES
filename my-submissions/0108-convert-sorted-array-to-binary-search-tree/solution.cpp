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
    TreeNode* helper(vector<int>& nums,int startIdx, int endIdx) {
        if(startIdx > endIdx) return NULL;
        int middle = (startIdx+endIdx)/2;
        TreeNode * root = new TreeNode(nums[middle]);

        root->left = helper(nums,startIdx,middle-1);
        root->right = helper(nums,middle+1,endIdx);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int startIdx = 0;
        int endIdx = nums.size()-1;
        return helper(nums,startIdx,endIdx);
    }
};
