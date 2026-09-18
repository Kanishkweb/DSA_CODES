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
    int searchIdx(int val , vector<int>&preorder, int start , int end){
        int ans = end;
        for(int i = start;i<=end;i++){
            if(preorder[i] > val){
                ans =  i-1;
                break;
            }
        }
        return ans;
    }
    TreeNode* traverse(vector<int>&preorder,int start, int end){
        if(start > end) return nullptr;
        TreeNode * root = new TreeNode(preorder[start]);
        int middle = searchIdx(root->val , preorder, start ,end);
        // left
        root->left = traverse(preorder,start+1,middle);
        // right
        root->right = traverse(preorder,middle+1,end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // root left right;
        int n = preorder.size();
        return traverse(preorder,0,n-1);

    }
};
