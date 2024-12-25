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
var largestValues = function (root) {
    if(root == null) return [];
    if(!root.left && !root.right) return [root.val];
    let result = [];
    let temp = -Infinity;
    let queue = [];
    queue.push(root);
    queue.push(0);
    while (queue.length > 0) {
        let front = queue.shift();
        if (front == 0) {
            if (queue.length > 0) {
                queue.push(0);
                result.push(temp);
                temp = -Infinity;
                continue;
            } 
            if(queue.length == 0){
                result.push(temp);
                continue;
            }
        }
        temp = Math.max(temp, front.val);
        if (front.left != null) {
            queue.push(front.left);
        }
        if (front.right != null) {
            queue.push(front.right)
        }
    }
    return result;
};
