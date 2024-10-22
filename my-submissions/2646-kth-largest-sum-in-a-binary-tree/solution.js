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
    let maxHeap = new MaxPriorityQueue({ compare: (a, b) => b - a })
    
    function dfs(childArr){
        if(childArr.length===0)return
        let sum=0
        let nextChildArr=[]
        for(let child of childArr){
            sum+=child.val
            if(child.left)nextChildArr.push(child.left)
            if(child.right)nextChildArr.push(child.right)
        }
        maxHeap.enqueue(sum)
        dfs(nextChildArr)
    }

    dfs([root])

    let top 
    while(k){
        top = maxHeap.dequeue()
        k--
    }
    return top||-1
};
