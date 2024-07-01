/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
let result;
var postorderTraversal = function (root) {
    result = [];
    post(root);
    return result;
};

function post(r) {
    if (r == null) return;
    post(r.left);
    post(r.right);
    result.push(r.val);
}
