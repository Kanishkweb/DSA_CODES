/**
 * @param {string} source
 * @param {string} target
 * @param {character[]} original
 * @param {character[]} changed
 * @param {number[]} cost
 * @return {number}
 */
var minimumCost = function (source, target, original, changed, cost) {
    const ALPHABET_SIZE = 26;
    const INF = Infinity;

    // Step 1: Initialize distance matrix
    const dist = Array.from({ length: ALPHABET_SIZE }, () => Array(ALPHABET_SIZE).fill(INF));

    // Each character can be transformed into itself with zero cost
    for (let i = 0; i < ALPHABET_SIZE; i++) {
        dist[i][i] = 0;
    }

    // Step 2: Populate initial edges with given transformations
    for (let i = 0; i < original.length; i++) {
        const from = original[i].charCodeAt(0) - 'a'.charCodeAt(0);
        const to = changed[i].charCodeAt(0) - 'a'.charCodeAt(0);
        dist[from][to] = Math.min(dist[from][to], cost[i]);
    }

    // Step 3: Run Floyd-Warshall algorithm to find all-pairs shortest paths
    for (let k = 0; k < ALPHABET_SIZE; k++) {
        for (let i = 0; i < ALPHABET_SIZE; i++) {
            for (let j = 0; j < ALPHABET_SIZE; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Step 4: Calculate the total cost to transform source into target
    let totalCost = 0;
    for (let i = 0; i < source.length; i++) {
        const srcChar = source[i].charCodeAt(0) - 'a'.charCodeAt(0);
        const tgtChar = target[i].charCodeAt(0) - 'a'.charCodeAt(0);

        if (dist[srcChar][tgtChar] === INF) {
            return -1; // Transformation from srcChar to tgtChar is impossible
        }

        totalCost += dist[srcChar][tgtChar];
    }

    return totalCost;
};
