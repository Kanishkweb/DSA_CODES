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
class BSTIterator {
public:
    vector<int> arr;
    int pointer = 0; // pointing 0 index in the vector arr;
    void inOrder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inOrder(root->left);
        arr.push_back(root->val);
        inOrder(root->right);
    }
    BSTIterator(TreeNode* root) {
        // perform inorder to store the values in the array;
        inOrder(root);
        // now arr have the inorder traversal all values;
    }

    int next() {
        pointer++;
        // if (pointer < arr.size()) {
        //     int ans = arr[pointer-1];
        //     return ans;
        // }
        
        return arr[pointer-1];
    }

    bool hasNext() {
        if (pointer < arr.size()) {
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
