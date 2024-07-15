/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[][]} descriptions
 * @return {TreeNode}
 */

var createBinaryTree = function (descriptions) {
    let op = {};
    let hasParent = new Set();

    for (let desc of descriptions) {
        if (!op[desc[0]]) {
            op[desc[0]] = new TreeNode(desc[0]);
        }
        if (!op[desc[1]]) {
            op[desc[1]] = new TreeNode(desc[1]);
        }
        hasParent.add(desc[1]);
    }

    let root = null;
    for (let desc of descriptions) {
        if (desc[2] === 1) { // left
            op[desc[0]].left = op[desc[1]];
        } else { // right
            op[desc[0]].right = op[desc[1]];
        }
        if (!hasParent.has(desc[0])) {
            root = op[desc[0]];
        }
    }

    return root;
};
