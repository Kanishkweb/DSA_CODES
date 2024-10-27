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
 * @param {number} k
 * @return {number}
 */
var kthLargestLevelSum = function (root, k) {
    if (root == null) return [];
    let queue = [];
    let res = [];
    let temp = 0;
    // put the first root element in the queue
    // also put a null after that
    queue.push(root); // enqueue
    queue.push(null); // enqueue
    while (queue.length != 0) {
        let getfront = queue.shift() // getfront
        if (getfront == null) {
            res.push(temp);
            temp = 0;
            // also dequeue null already done // now enqueue null
            if (queue.length != 0) {
                queue.push(null);
            }
            continue;
        }
        temp += getfront.val;
        if (getfront.left != null) {
            queue.push(getfront.left);
        }
        if (getfront.right != null) {
            queue.push(getfront.right);
        }
    }
    res.sort((a,b) =>{
        return b - a;
    })
    if (res.length < k) {
        return -1;
    }
    return res[k - 1];
};
