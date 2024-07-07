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

function f(root) {
    if (root == null) {
        return {
            isBST: true, max: -Infinity, min: Infinity
        }
    }
    let left = f(root.left);
    let right = f(root.right);
    if (left.isBST && right.isBST && left.max < root.val && root.val < right.min) {
        return { isBST: true, max: Math.max(left.max, right.max, root.val), min: Math.min(left.min, right.min, root.val) }
    } else {
        return { isBST: false, max: Math.max(left.max, right.max, root.val), min: Math.min(left.min, right.min, root.val) }
    }
}

var isValidBST = function (root) {
    return f(root).isBST;
};

