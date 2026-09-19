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
    unordered_map<int, int> mp;
    int isAvail(int val, int start, int end) {
        int idx = mp[val];
        if (start <= idx && idx <= end) {
            return true;
        }
        return false;
    }
    TreeNode* buildBST(vector<int>& preorder, vector<int>& inorder, int &idx,
                       int start, int end) {
        if (start > end)
            return nullptr;
        int val = preorder[idx];
        TreeNode* root;
        if (isAvail(val, start, end)) {
            root = new TreeNode(val);
            idx++;
        } else {
            root = nullptr;
        }
        // find the root in inorder and set start and end
        int mid = mp[val];
        if (root) {

            root->left = buildBST(preorder, inorder, idx, start, mid - 1);
            root->right = buildBST(preorder, inorder, idx, mid + 1, end);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int start = 0;
        int end = n - 1;
        int idx = 0;

        int i = 0;
        for (auto& val : inorder) {
            mp[val] = i;
            i++;
        }
        return buildBST(preorder, inorder, idx, start, end);
    }
};
