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
 * @return {TreeNode}
 */

function reverse(temp, root) {
    for (let i = 0, j = temp.length - 1; i <= j; i++, j--) {
        let op = temp[i].val;
        temp[i].val = temp[j].val;
        temp[j].val = op;
    }
    // return root;
}

var reverseOddLevels = function (root) {
    let queue = [];
    let isOdd = false;
    queue.push(root);
    queue.push(0);
    let temp = [];
    while (queue.length > 0) {
        let front = queue.shift();
        if (front == 0) {
            if (isOdd) {
                reverse(temp, root);
            }
            if (queue.length == 0) {
                continue;
            } else {
                queue.push(0);
                temp = [];
                if (isOdd == false) {
                    isOdd = true
                } else {
                    isOdd = false
                }
                continue;
            }
        }
        temp.push(front);
        if (front.left) {
            queue.push(front.left)
        }
        if (front.right) {
            queue.push(front.right)
        }
    }
    return root;
};
