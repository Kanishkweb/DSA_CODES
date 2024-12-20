/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} distanceThreshold
 * @return {number}
 */
function dijkstras(src, adj, SPM) {
    let pq = [];
    pq.push([0, src]);
    while (pq.length > 0) {
        let weight = pq[0][0];
        let node = pq[0][1];
        pq.shift(); // first element in out priority queue
        for (let op in adj[node]) {
            let currWeight = adj[node][op][1];
            let nNode = adj[node][op][0];
            let nWeight = SPM[src][nNode];
            let pastWeight = SPM[src][node];
            if (pastWeight + currWeight < nWeight) {
                let lop = pastWeight + currWeight;
                SPM[src][nNode] = lop;
                // also push in pq
                pq.push([lop, nNode]);
                pq.sort((a, b) => {
                    if (a[0] == b[0]) {
                        return a[1] - b[1];
                    } else {
                        return a[0] - b[0];
                    }
                });
            }
        }
    }
}
var findTheCity = function (n, edges, distanceThreshold) {
    let adj = [];
    let SPM = [];
    for (let i = 0; i < n; i++) {
        let temp = Array(n).fill(Infinity);
        temp[i] = 0; // shortest distance from the source is always zero
        SPM.push(temp);
        let op = [];
        adj.push(op);
    }
    for (let i = 0; i < edges.length; i++) {
        let u = edges[i][0];
        let v = edges[i][1];
        let w = edges[i][2];
        adj[u].push([v, w]);
        adj[v].push([u, w]);
    }
    for (let i = 0; i < n; i++) {
        // sending source node to the Dijkstras Algo
        dijkstras(i, adj, SPM);
    }
    // now our last step is to iterate the SPM to find the city
    let finalAns = Infinity;
    let cityName = -Infinity;
    for (let i = 0; i < SPM.length; i++) {
        // i means the ith city
        let ttCity = 0;
        for (let j = 0; j < SPM[0].length; j++) {
            let temp = SPM[i][j];
            if (temp <= distanceThreshold && temp != 0) {
                ttCity++;
            }
        }
        if (finalAns > ttCity) {
            finalAns = ttCity;
            cityName = i;
        } else if (finalAns == ttCity) {
            cityName = Math.max(cityName, i);
        }
    }
    return cityName;
};
