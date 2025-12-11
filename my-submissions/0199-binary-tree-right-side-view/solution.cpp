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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        if(root->left == NULL && root->right == NULL) return {root->val};
        vector<vector<int>>result;
        vector<int>tempArr;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp = q.front();
            if(q.front() == NULL){
                q.pop();
                result.push_back(tempArr);
                if(q.empty()){
                    break;
                }
                tempArr = {};
                q.push(NULL);
                continue;
            }
            tempArr.push_back(temp->val);
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
            q.pop();
        }
        vector<int>finalRes;
        for(int i = 0;i<result.size();i++){
            int lastIdx = result[i].size()-1;
            int lastVal = result[i][lastIdx];
            finalRes.push_back(lastVal);
        }
        return finalRes;
    }
};
