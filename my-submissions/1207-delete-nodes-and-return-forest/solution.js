
/**
 * @param {TreeNode} root
 * @param {number[]} to_delete
 * @return {TreeNode[]}
 */
var delNodes = function(root, to_delete) {
    const toDelete = new Set(to_delete);
    const forest = [];
    
    function deleteNodes(node, isRoot) {
        if (!node) return null;
        
        const shouldDelete = toDelete.has(node.val);
        
        if (isRoot && !shouldDelete) {
            forest.push(node);
        }
        
        node.left = deleteNodes(node.left, shouldDelete);
        node.right = deleteNodes(node.right, shouldDelete);
        
        return shouldDelete ? null : node;
    }
    
    deleteNodes(root, true);
    return forest;
};
