//JavaScript Code
/**
 * // Definition for a _Node.
 * function _Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {_Node|null} root
 * @return {number[]}
 */
var postorder = function(root) {
    const arr = []
    const postOrder = ((root) =>{
        if(root == undefined)
            return
        for(let child of root.children)
            postOrder(child)
        
        arr.push(root.val)
    })
    
    postOrder(root)
    return arr
};
