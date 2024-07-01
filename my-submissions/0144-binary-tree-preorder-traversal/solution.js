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
var preorderTraversal = function (root) {
    result = []
    pre(root);
    return result;
};

function pre(r) {
    if (r == null) return;
    result.push(r.val);
    pre(r.left);
    pre(r.right);
}
