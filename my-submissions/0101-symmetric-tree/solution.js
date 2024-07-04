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
 * @return {boolean}
 */

function f(r1, r2) {
    if (r1 == null && r2 == null) return true;
    if (r1 == null) {
        return false;
    }
    if (r2 == null) {
        return false;
    }

    return (r1.val == r2.val) && f(r1.left, r2.right) && f(r1.right, r2.left);
};

var isSymmetric = function (root) {
    return f(root, root)
};
