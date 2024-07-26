/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} distanceThreshold
 * @return {number}
 */
var findTheCity = function (n, edges, distanceThreshold) {
    // Create the graph as an adjacency list
    const graph = Array.from({ length: n }, () => []);
    for (const [u, v, w] of edges) {
        graph[u].push([v, w]);
        graph[v].push([u, w]);
    }

    // Dijkstra's algorithm to find the shortest paths from a starting city
    const dijkstra = (start) => {
        const dist = Array(n).fill(Infinity);
        dist[start] = 0;
        const pq = new MinPriorityQueue();
        pq.enqueue(start, 0);

        while (!pq.isEmpty()) {
            const { element: u, priority: currentDist } = pq.dequeue();

            if (currentDist > dist[u]) continue;

            for (const [v, weight] of graph[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.enqueue(v, dist[v]);
                }
            }
        }
        return dist;
    };

    let minReachableCities = Infinity;
    let city = -1;

    for (let i = 0; i < n; ++i) {
        const dist = dijkstra(i);
        const reachableCities = dist.filter(d => d <= distanceThreshold).length;

        if (reachableCities <= minReachableCities) {
            minReachableCities = reachableCities;
            city = i;
        }
    }

    return city;
};
