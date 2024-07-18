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
 * @param {number} distance
 * @return {number}
 */
var countPairs = function (root, distance) {
    let result = 0;

    const dfs = (node) => {
        if (!node) return [];
        if (!node.left && !node.right) return [1];

        const left = dfs(node.left);
        const right = dfs(node.right);

        for (let l of left) {
            for (let r of right) {
                if (l + r <= distance) result++;
            }
        }

        const distances = [];
        for (let l of left) {
            if (l + 1 <= distance) distances.push(l + 1);
        }
        for (let r of right) {
            if (r + 1 <= distance) distances.push(r + 1);
        }

        return distances;
    };

    dfs(root);
    return result;
};
