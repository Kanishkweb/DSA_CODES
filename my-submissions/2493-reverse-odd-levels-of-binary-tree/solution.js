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
var reverseOddLevels = function (root) {
    // Edge case: if the tree is empty, return the root (null)
    if (root === null) return root;

    // Queue for level order traversal (using an array for the queue)
    let queue = [root];

    // Flag to keep track of odd levels
    let isOddLevel = false;

    // Perform level order traversal
    while (queue.length > 0) {
        let levelSize = queue.length;  // Number of nodes at the current level
        let currentLevelNodes = [];

        // Process nodes at the current level
        for (let i = 0; i < levelSize; i++) {
            let node = queue.shift();  // Dequeue the front node

            // Add children to the queue for the next level
            if (node.left !== null) queue.push(node.left);
            if (node.right !== null) queue.push(node.right);

            // Store the node at the current level
            currentLevelNodes.push(node);
        }

        // If we are at an odd level, reverse the node values
        if (isOddLevel) {
            let left = 0, right = currentLevelNodes.length - 1;
            while (left < right) {
                // Swap the values of the nodes at the two ends
                let temp = currentLevelNodes[left].val;
                currentLevelNodes[left].val = currentLevelNodes[right].val;
                currentLevelNodes[right].val = temp;
                left++;
                right--;
            }
        }

        // Toggle the flag to switch between odd and even levels
        isOddLevel = !isOddLevel;
    }

    // Return the root after modifying the tree
    return root;
};
