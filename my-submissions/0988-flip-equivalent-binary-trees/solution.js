/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */
var dfs = function(node1, node2) {
    // If both nodes are null, they are equivalent
    if (!node1 && !node2) return true;
    // If only one is null, they are not equivalent
    if (!node1 || !node2) return false;

    // Check if current nodes have the same value and 
    // (1) their children match directly or 
    // (2) their children match when flipped
    return node1.val === node2.val && 
           ((dfs(node1.left, node2.left) && dfs(node1.right, node2.right)) || 
            (dfs(node1.left, node2.right) && dfs(node1.right, node2.left)));
};

var flipEquiv = function(root1, root2) {
    return dfs(root1, root2);
};
