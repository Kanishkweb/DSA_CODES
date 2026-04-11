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
    bool findThePath(TreeNode* root, int& startValue, string& rootToStart) {
        // base case
        if (root == NULL)
            return false;
        if (root->val == startValue)
            return true;
        rootToStart.push_back('L');
        if (findThePath(root->left, startValue, rootToStart))
            return true;
        rootToStart.pop_back();
        rootToStart.push_back('R');
        if (findThePath(root->right, startValue, rootToStart))
            return true;
        rootToStart.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rootToStart = "";
        string rootToDest = "";

        findThePath(root, startValue, rootToStart);
        findThePath(root, destValue, rootToDest);

        int l = 0;
        while (l < rootToStart.length() && l < rootToDest.length() &&
               rootToStart[l] == rootToDest[l]) {
            l++;
        }

        string result = "";
        for (int i = l; i < rootToStart.length(); i++)
            result.push_back('U');
        for (int i = l; i < rootToDest.length(); i++) {
            result.push_back(rootToDest[i]);
        }
        return result;
    }
};
