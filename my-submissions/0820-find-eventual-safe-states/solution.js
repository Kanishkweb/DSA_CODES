/**
 * @param {number[][]} graph
 * @return {number[]}
 */
var eventualSafeNodes = function (graph) {
    const n = graph.length;
    const reversedGraph = Array.from({ length: n }, () => []);
    const outdegree = new Array(n).fill(0);
    const queue = [];
    const safeNodes = [];

    // Step 1: Build the reversed graph and calculate outdegrees
    for (let i = 0; i < n; i++) {
        for (const neighbor of graph[i]) {
            reversedGraph[neighbor].push(i);
        }
        outdegree[i] = graph[i].length;
    }

    // Step 2: Add terminal nodes (nodes with outdegree 0) to the queue
    for (let i = 0; i < n; i++) {
        if (outdegree[i] === 0) {
            queue.push(i);
        }
    }

    // Step 3: Process nodes in the queue
    while (queue.length > 0) {
        const node = queue.shift();
        safeNodes.push(node);
        for (const neighbor of reversedGraph[node]) {
            outdegree[neighbor]--;
            if (outdegree[neighbor] === 0) {
                queue.push(neighbor);
            }
        }
    }

    // Step 4: Sort the safe nodes
    return safeNodes.sort((a, b) => a - b);
};
