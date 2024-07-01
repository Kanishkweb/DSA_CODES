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
var inorderTraversal = function (root) {
    result = [];
    inOrder(root)
    return result;
};
function inOrder(r) {
    if (r == null) return;
    inOrder(r.left);
    result.push(r.val);
    inOrder(r.right);
}
