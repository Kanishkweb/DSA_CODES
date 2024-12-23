var minimumOperations = function(root) {
    curr = [root]
    ans = 0
    while (curr.length > 0) {
        size = curr.length
        tree_level = curr.map(node => node.val)
        sort_arr = tree_level.map(t => t)
        sort_arr.sort((a, b) => a - b)
        d = new Map()
        for (i = 0; i < size; i++) d.set(sort_arr[i], i)
        for (i = 0; i < size; i++) {
            j = d.get(tree_level[i])
            while (i != j) {
                ans++
                t = tree_level[j]
                tree_level[j] = tree_level[i]
                tree_level[i] = t
                j = d.get(t)
            }
        }
        next = []
        for (i = 0; i < size; i++) {
            node = curr[i]
            if (node.left)
                next.push(node.left)
            if (node.right)
                next.push(node.right)
        }
        curr = next
    }
    return ans
};
