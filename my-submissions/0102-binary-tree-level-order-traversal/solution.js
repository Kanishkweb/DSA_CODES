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
 * @return {number[][]}
 */
var levelOrder = function (root) {
    if(root == null) return [];
    let queue = [];
    let res = [];
    let temp = [];
    // put the first root element in the queue
    // also put a null after that
    queue.push(root); // enqueue
    queue.push(null); // enqueue
    while (queue.length != 0) {
        let getfront = queue.shift() // getfront
        if (getfront == null) {
            res.push(temp);
            temp = [];
            // also dequeue null already done // now enqueue null
            if (queue.length != 0) {
                queue.push(null);
            }
            continue;
        }
        temp.push(getfront.val);
        if (getfront.left != null) {
            queue.push(getfront.left);
        }
        if (getfront.right != null) {
            queue.push(getfront.right);
        }
    }
    return res;
};
