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
    void insert(TreeNode*& root, map<pair<int, int>, int>& mp) {
        if (mp.find({root->val, 1}) != mp.end()) {
            root->left = new TreeNode(mp[{root->val, 1}]);
            insert(root->left,mp);
        }
        if (mp.find({root->val, 0}) != mp.end()) {
            root->right = new TreeNode(mp[{root->val, 0}]);
            insert(root->right,mp);
        }
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // step 1 - find the root
        set<int> st;
        map<pair<int, int>, int> mp;
        for (auto& node : descriptions) {
            int parent = node[0];
            int child = node[1];
            int isLeft = node[2];
            mp[{parent, isLeft}] = child;
            st.insert(node[1]);
        }
        TreeNode* root;
        for (auto& node : descriptions) {
            if (st.find(node[0]) == st.end()) {
                root = new TreeNode(node[0]);
            }
        }
        insert(root, mp);
        return root;
    }
};
